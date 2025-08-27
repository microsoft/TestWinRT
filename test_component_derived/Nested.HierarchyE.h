#pragma once
#include "Nested.HierarchyD.h"

namespace winrt::test_component_derived::Nested::implementation
{
    struct HierarchyE : implements<HierarchyE, test_component_derived::Nested::implementation::HierarchyD>
    {
        HierarchyE() = default;

        hstring GetRuntimeClassName() const noexcept { return L"test_component_derived.Nested.HierarchyE"; }
    };
}
