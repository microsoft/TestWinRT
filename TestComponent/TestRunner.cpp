#include "pch.h"
#include "TestRunner.h"
#include "TestRunner.g.cpp"

#define TEST_REQUIRE(test, expression) { if (!(expression)) throw winrt::hresult_invalid_argument(test); }

namespace winrt::TestComponent::implementation
{
    struct Tests : implements<Tests, ITests>
    {
    private:

        uint32_t m_counter{};
        const uint32_t m_total{ 3 };

    public:

        void abi_enter()
        {
            ++m_counter;
        }

        uint32_t Percentage() const
        {
            return m_counter * 100 / m_total;
        }

        void T1_Simple()
        {
        }
        bool T2_Bool(bool a, bool& b)
        {
            b = a;
            return a;
        }
        int8_t T3_UInt8(uint8_t a, uint8_t& b)
        {
            b = a;
            return a;
        }
    };

    void RunTests(ITests const& tests)
    {
        tests.T1_Simple();
        {
            bool const a = true;
            bool b;
            bool c = tests.T2_Bool(true, b);
            TEST_REQUIRE(L"T2_Bool", b && c);
        }
        {
            uint8_t a = 123;
            uint8_t b;
            uint8_t c = tests.T3_UInt8(a, b);
            TEST_REQUIRE(L"T3_UInt8", a == b && a == c);
        }
    }

    void TestRunner::TestCallee(ITests const& tests)
    {
        RunTests(tests);
    }

    uint32_t TestRunner::TestCaller(TestHandler const& caller)
    {
        auto tests = make_self<Tests>();
        caller(*tests);
        return tests->Percentage();
    }

    void TestRunner::TestSelf()
    {
        TestRunner::TestCallee(make<Tests>());

        uint32_t percentage = TestRunner::TestCaller([](ITests const& tests)
            {
                RunTests(tests);
            });

        TEST_REQUIRE(L"Less than 100% coverage", percentage == 100);
        percentage = TestRunner::TestCaller([](auto&&) {});
        TEST_REQUIRE(L"TestSelf", percentage == 0);

        percentage = TestRunner::TestCaller([](ITests const& tests)
            {
                tests.T1_Simple();
            });

        TEST_REQUIRE(L"TestSelf", percentage > 0 && percentage < 100);
    }
}
