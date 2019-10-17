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
        const uint32_t m_total{ 13 };

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
        uint8_t T3_UInt8(uint8_t a, uint8_t& b)
        {
            b = a;
            return a;
        }
        uint16_t T4_UInt16(uint16_t a, uint16_t& b)
        {
            b = a;
            return a;
        }
        uint32_t T5_UInt32(uint32_t a, uint32_t& b)
        {
            b = a;
            return a;
        }
        uint64_t T6_UInt64(uint64_t a, uint64_t& b)
        {
            b = a;
            return a;
        }
        int16_t T7_Int16(int16_t a, int16_t& b)
        {
            b = a;
            return a;
        }
        int32_t T8_Int32(int32_t a, int32_t& b)
        {
            b = a;
            return a;
        }
        int64_t T9_Int64(int64_t a, int64_t& b)
        {
            b = a;
            return a;
        }
        float T10_Single(float a, float& b)
        {
            b = a;
            return a;
        }
        double T11_Double(double a, double& b)
        {
            b = a;
            return a;
        }
        char16_t T12_Char(char16_t a, char16_t& b)
        {
            b = a;
            return a;
        }
        hstring T13_String(hstring const& a, hstring& b)
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
        {
            uint16_t a = 123;
            uint16_t b;
            uint16_t c = tests.T4_UInt16(a, b);
            TEST_REQUIRE(L"T4_UInt16", a == b && a == c);
        }
        {
            uint32_t a = 123;
            uint32_t b;
            uint32_t c = tests.T5_UInt32(a, b);
            TEST_REQUIRE(L"T5_UInt32", a == b && a == c);
        }
        {
            uint64_t a = 123;
            uint64_t b;
            uint64_t c = tests.T6_UInt64(a, b);
            TEST_REQUIRE(L"T6_UInt64", a == b && a == c);
        }
        {
            int16_t a = 123;
            int16_t b;
            int16_t c = tests.T7_Int16(a, b);
            TEST_REQUIRE(L"T7_Int16", a == b && a == c);
        }
        {
            int32_t a = 123;
            int32_t b;
            int32_t c = tests.T8_Int32(a, b);
            TEST_REQUIRE(L"T8_Int32", a == b && a == c);
        }
        {
            int64_t a = 123;
            int64_t b;
            int64_t c = tests.T9_Int64(a, b);
            TEST_REQUIRE(L"T9_Int64", a == b && a == c);
        }
        {
            float a = 12.3f;
            float b;
            float c = tests.T10_Single(a, b);
            TEST_REQUIRE(L"T10_Single", a == b && a == c);
        }
        {
            double a = 12.3;
            double b;
            double c = tests.T11_Double(a, b);
            TEST_REQUIRE(L"T11_Double", a == b && a == c);
        }
        {
            char16_t a = L'W';
            char16_t b;
            char16_t c = tests.T12_Char(a, b);
            TEST_REQUIRE(L"T12_Char", a == b && a == c);
        }
        {
            hstring a = L"WinRT";
            hstring b;
            hstring c = tests.T13_String(a, b);
            TEST_REQUIRE(L"T13_String", a == b && a == c);
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

        TEST_REQUIRE(L"Test cover is " + to_hstring(percentage) + L"%", percentage == 100);
        percentage = TestRunner::TestCaller([](auto&&) {});
        TEST_REQUIRE(L"TestSelf", percentage == 0);

        percentage = TestRunner::TestCaller([](ITests const& tests)
            {
                tests.T1_Simple();
            });

        TEST_REQUIRE(L"TestSelf", percentage > 0 && percentage < 100);
    }
}
