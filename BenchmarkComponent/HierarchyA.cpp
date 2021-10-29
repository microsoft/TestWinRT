#include "pch.h"
#include "HierarchyA.h"
#include "HierarchyA.g.cpp"

namespace winrt
{
    template <typename T, typename Allocator = std::allocator<T>>
    Windows::Foundation::Collections::IVectorView<T> single_threaded_vector_view(std::vector<T, Allocator>&& values = {})
    {
        return make<impl::input_vector_view<T, std::vector<T, Allocator>>>(std::move(values));
    }

}

namespace winrt::BenchmarkComponent::implementation
{
    Windows::Foundation::Collections::IVector<int32_t> HierarchyA::GetIntList()
    {
        Windows::Foundation::Collections::IVector<int32_t> vec{ winrt::single_threaded_vector<int32_t>() };
        for (auto i = 0; i < 1000; i++)
        {
            vec.Append(i);
        }
        return vec;
    }
    Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> HierarchyA::GetList()
    {
        Windows::Foundation::Collections::IVector<Windows::Foundation::IInspectable> vec{ winrt::single_threaded_vector<Windows::Foundation::IInspectable>() };
        for (auto i = 0; i < 1000; i++)
        {
            vec.Append(winrt::box_value(100));
        }
        return vec;
    }
    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> BenchmarkComponent::implementation::HierarchyA::GetXamlList()
    {
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> vec{ winrt::single_threaded_observable_vector<Windows::Foundation::IInspectable>() };
        for (auto i = 0; i < 1000; i++)
        {
            vec.Append(winrt::box_value(100));
        }
        return vec;
    }
}
