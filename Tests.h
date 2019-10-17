#pragma once

#include <winrt/TestComponent.h>

#define TEST_REQUIRE(name, expression) { if (!(expression)) throw winrt::hresult_invalid_argument(name); }

namespace winrt
{
    using namespace TestComponent;
}

struct Tests : winrt::implements<Tests, winrt::ITests>
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

inline void RunTests(winrt::ITests const& tests)
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
