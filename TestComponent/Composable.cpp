#include "pch.h"
#include "Composable.h"
#include "Composable.g.cpp"

namespace winrt::TestComponent::implementation
{
    Composable::Composable(int32_t init) :
        m_value(init)
    {
    }

    int32_t Composable::Value()
    {
        return m_value;
    }
}
