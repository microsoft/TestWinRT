#include "pch.h"
#include "Simple.h"
#include "Simple.g.cpp"

// Validates that WINRT_FAST_ABI_SIZE may be overridden using /D.
#pragma detect_mismatch("WINRT_FAST_ABI_SIZE", "50")

namespace winrt::test_component_fast::implementation
{
    hstring Simple::Method1()
    {
        return L"Method1";
    }
    hstring Simple::Method2()
    {
        return L"Method2";
    }
    hstring Simple::Method3()
    {
        return L"Method3";
    }
    hstring Simple::Method4()
    {
        return L"Method4";
    }
    hstring Simple::Method5()
    {
        return L"Method5";
    }
    hstring Simple::Method6()
    {
        return L"Method6";
    }
    hstring Simple::Method7()
    {
        return L"Method7";
    }
    hstring Simple::Method8()
    {
        return L"Method8";
    }
    hstring Simple::Method9()
    {
        return L"Method9";
    }
    hstring Simple::Property1()
    {
        return this->_property1;
    }
    void Simple::Property1(hstring val)
    {
        this->_property1 = val;
    }
    hstring Simple::Property2()
    {
        return L"Property2";
    }
    hstring Simple::Property3()
    {
        return this->_property3;
    }
    void Simple::Property3(hstring val)
    {
        this->_property3 = val;
    }
    winrt::event_token Simple::Event0(test_component_fast::EventHandler0 const& handler)
    {
        return _event0.add(handler);
    }
    void Simple::Event0(winrt::event_token const& token) noexcept
    {
        _event0.remove(token);
    }
    void Simple::InvokeEvent0()
    {
        _event0();
    }
}
