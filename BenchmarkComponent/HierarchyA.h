#pragma once
#include "HierarchyA.g.h"

namespace winrt::BenchmarkComponent::implementation
{
    struct HierarchyA : HierarchyAT<HierarchyA>
    {
        HierarchyA() = default;

        Windows::Foundation::Collections::IVector<int32_t> GetIntList();
        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> GetList();
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> GetXamlList();
    };
}
namespace winrt::BenchmarkComponent::factory_implementation
{
    struct HierarchyA : HierarchyAT<HierarchyA, implementation::HierarchyA>
    {
    };
}
