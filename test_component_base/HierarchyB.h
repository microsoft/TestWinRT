#pragma once
#include "HierarchyB.g.h"
#include "HierarchyA.h"

namespace winrt::test_component_base::implementation
{
    struct HierarchyB : HierarchyBT<HierarchyB, test_component_base::implementation::HierarchyA>
    {
        HierarchyB() = default;

        HierarchyB(hstring const& name);
        virtual winrt::hstring HierarchyA_Method();
        virtual winrt::hstring HierarchyB_Method();
    };
}
namespace winrt::test_component_base::factory_implementation
{
    struct HierarchyB : HierarchyBT<HierarchyB, implementation::HierarchyB>
    {
    };
}
