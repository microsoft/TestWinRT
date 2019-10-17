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
        const uint32_t m_total{ 18 };

    public:

        void abi_enter()
        {
            ++m_counter;
        }

        uint32_t Percentage() const
        {
            return m_counter * 100 / m_total;
        }

        void Simple()
        {
        }

        auto Params_Bool(bool a, bool& b)
        {
            b = a;
            return a;
        }
        auto Params_UInt8(uint8_t a, uint8_t& b)
        {
            b = a;
            return a;
        }
        auto Params_UInt16(uint16_t a, uint16_t& b)
        {
            b = a;
            return a;
        }
        auto Params_UInt32(uint32_t a, uint32_t& b)
        {
            b = a;
            return a;
        }
        auto Params_UInt64(uint64_t a, uint64_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Int16(int16_t a, int16_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Int32(int32_t a, int32_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Int64(int64_t a, int64_t& b)
        {
            b = a;
            return a;
        }
        auto Params_Single(float a, float& b)
        {
            b = a;
            return a;
        }
        auto Params_Double(double a, double& b)
        {
            b = a;
            return a;
        }
        auto Params_Char(char16_t a, char16_t& b)
        {
            b = a;
            return a;
        }
        auto Params_String(hstring const& a, hstring& b)
        {
            b = a;
            return a;
        }

        auto ArrayParams_Bool(array_view<bool const> a, array_view<bool> b, com_array<bool>& c)
        {
            TEST_REQUIRE(L"ArrayParams_Bool", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_Bool", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<bool>(a.begin(), a.end());
            return com_array<bool>(a.begin(), a.end());
        }

        auto ArrayParams_UInt8(array_view<uint8_t const> a, array_view<uint8_t> b, com_array<uint8_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt8", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt8", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint8_t>(a.begin(), a.end());
            return com_array<uint8_t>(a.begin(), a.end());
        }
        auto ArrayParams_UInt16(array_view<uint16_t const> a, array_view<uint16_t> b, com_array<uint16_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt16", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt16", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint16_t>(a.begin(), a.end());
            return com_array<uint16_t>(a.begin(), a.end());
        }
        auto ArrayParams_UInt32(array_view<uint32_t const> a, array_view<uint32_t> b, com_array<uint32_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt32", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt32", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint32_t>(a.begin(), a.end());
            return com_array<uint32_t>(a.begin(), a.end());
        }
        auto ArrayParams_UInt64(array_view<uint64_t const> a, array_view<uint64_t> b, com_array<uint64_t>& c)
        {
            TEST_REQUIRE(L"ArrayParams_UInt64", a.size() == b.size());
            TEST_REQUIRE(L"ArrayParams_UInt64", c.size() == 0);
            std::copy(a.begin(), a.end(), b.begin());
            c = com_array<uint64_t>(a.begin(), a.end());
            return com_array<uint64_t>(a.begin(), a.end());
        }
    };

    template <typename T>
    bool operator==(std::array<T, 3> const& left, com_array<T> const& right)
    {
        return std::equal(left.begin(), left.end(), right.begin(), right.end());
    }

    void RunTests(ITests const& tests)
    {
        tests.Simple();
        {
            bool const a = true;
            bool b;
            bool c = tests.Params_Bool(true, b);
            TEST_REQUIRE(L"Params_Bool", b && c);
        }
        {
            uint8_t a = 123;
            uint8_t b;
            uint8_t c = tests.Params_UInt8(a, b);
            TEST_REQUIRE(L"Params_UInt8", a == b && a == c);
        }
        {
            uint16_t a = 123;
            uint16_t b;
            uint16_t c = tests.Params_UInt16(a, b);
            TEST_REQUIRE(L"Params_UInt16", a == b && a == c);
        }
        {
            uint32_t a = 123;
            uint32_t b;
            uint32_t c = tests.Params_UInt32(a, b);
            TEST_REQUIRE(L"Params_UInt32", a == b && a == c);
        }
        {
            uint64_t a = 123;
            uint64_t b;
            uint64_t c = tests.Params_UInt64(a, b);
            TEST_REQUIRE(L"Params_UInt64", a == b && a == c);
        }
        {
            int16_t a = 123;
            int16_t b;
            int16_t c = tests.Params_Int16(a, b);
            TEST_REQUIRE(L"Params_Int16", a == b && a == c);
        }
        {
            int32_t a = 123;
            int32_t b;
            int32_t c = tests.Params_Int32(a, b);
            TEST_REQUIRE(L"Params_Int32", a == b && a == c);
        }
        {
            int64_t a = 123;
            int64_t b;
            int64_t c = tests.Params_Int64(a, b);
            TEST_REQUIRE(L"Params_Int64", a == b && a == c);
        }
        {
            float a = 12.3f;
            float b;
            float c = tests.Params_Single(a, b);
            TEST_REQUIRE(L"Params_Single", a == b && a == c);
        }
        {
            double a = 12.3;
            double b;
            double c = tests.Params_Double(a, b);
            TEST_REQUIRE(L"Params_Double", a == b && a == c);
        }
        {
            char16_t a = L'W';
            char16_t b;
            char16_t c = tests.Params_Char(a, b);
            TEST_REQUIRE(L"Params_Char", a == b && a == c);
        }
        {
            hstring a = L"WinRT";
            hstring b;
            hstring c = tests.Params_String(a, b);
            TEST_REQUIRE(L"Params_String", a == b && a == c);
        }

        {
            std::array<bool, 3> a{ true,false,true };
            std::array<bool, 3> b;
            com_array<bool> c;
            com_array<bool> d = tests.ArrayParams_Bool(a, b, c);
            TEST_REQUIRE(L"ArrayParams_Bool", a == b && a == c && c == d);
        }
        {
            std::array<uint8_t, 3> a{ 1,2,3 };
            std::array<uint8_t, 3> b;
            com_array<uint8_t> c;
            com_array<uint8_t> d = tests.ArrayParams_UInt8(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt8", a == b && a == c && c == d);
        }
        {
            std::array<uint16_t, 3> a{ 1,2,3 };
            std::array<uint16_t, 3> b;
            com_array<uint16_t> c;
            com_array<uint16_t> d = tests.ArrayParams_UInt16(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt16", a == b && a == c && c == d);
        }
        {
            std::array<uint32_t, 3> a{ 1,2,3 };
            std::array<uint32_t, 3> b;
            com_array<uint32_t> c;
            com_array<uint32_t> d = tests.ArrayParams_UInt32(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt32", a == b && a == c && c == d);
        }
        {
            std::array<uint64_t, 3> a{ 1,2,3 };
            std::array<uint64_t, 3> b;
            com_array<uint64_t> c;
            com_array<uint64_t> d = tests.ArrayParams_UInt64(a, b, c);
            TEST_REQUIRE(L"ArrayParams_UInt64", a == b && a == c && c == d);
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
                tests.Simple();
            });

        TEST_REQUIRE(L"TestSelf", percentage > 0 && percentage < 100);
    }
}
