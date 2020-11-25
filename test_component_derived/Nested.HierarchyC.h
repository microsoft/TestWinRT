#pragma once
#include "Nested.HierarchyC.g.h"

namespace winrt::test_component_derived::Nested::implementation
{
    struct HierarchyC : HierarchyCT<HierarchyC, winrt::test_component_base::HierarchyB>
    {
        HierarchyC() = default;

        HierarchyC(hstring const& name);
        virtual winrt::hstring HierarchyB_Method();
        virtual winrt::hstring HierarchyC_Method();
    };
}
namespace winrt::test_component_derived::Nested::factory_implementation
{
    struct HierarchyC : HierarchyCT<HierarchyC, implementation::HierarchyC>
    {
    };
}
