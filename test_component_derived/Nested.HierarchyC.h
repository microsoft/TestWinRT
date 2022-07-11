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

        static winrt::test_component_derived::Nested::HierarchyC CreateDerivedHierarchyD();
        static Windows::Foundation::IInspectable CreateDerivedHierarchyDAsObject();
        static Windows::Foundation::Collections::IVector<winrt::test_component_derived::Nested::HierarchyC> CreateDerivedHierarchyDList();
        static Windows::Foundation::Collections::IVector <Windows::Foundation::IInspectable> CreateDerivedHierarchyDAsObjectList();
    };
}
namespace winrt::test_component_derived::Nested::factory_implementation
{
    struct HierarchyC : HierarchyCT<HierarchyC, implementation::HierarchyC>
    {
    };
}
