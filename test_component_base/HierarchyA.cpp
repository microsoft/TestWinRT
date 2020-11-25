#include "pch.h"
#include "HierarchyA.h"
#include "HierarchyA.g.cpp"

namespace winrt::test_component_base::implementation
{
    HierarchyA::HierarchyA(hstring const& name)
    {
        throw hresult_not_implemented();
    }
    winrt::hstring HierarchyA::HierarchyA_Method()
    {
        return L"HierarchyA.HierarchyA_Method";
    }
}
