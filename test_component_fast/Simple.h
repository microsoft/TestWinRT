#pragma once
#include "Simple.g.h"

namespace winrt::test_component_fast::implementation
{
    struct Simple : SimpleT<Simple>
    {
        Simple() = default;

        hstring Method1();
        hstring Method2();
        hstring Method3();
        hstring Property1();
        void Property1(hstring val);
        hstring Property2();
        hstring Property3();
        void Property3(hstring val);

        winrt::event_token Event0(test_component_fast::EventHandler0 const& handler);
        void Event0(winrt::event_token const& token) noexcept;
        void InvokeEvent0();
    private:
        hstring _property1 = L"";
        hstring _property3 = L"";
        winrt::event<test_component_fast::EventHandler0> _event0;
    };
}
namespace winrt::test_component_fast::factory_implementation
{
    struct Simple : SimpleT<Simple, implementation::Simple>
    {
    };
}
