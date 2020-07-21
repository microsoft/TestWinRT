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

    int32_t Composable::One()
    {
        return 1;
    }

    int32_t Composable::Two()
    {
        return 2;
    }

    int32_t Composable::Three()
    {
        return 3;
    }

    int32_t Composable::Four()
    {
        return 4;
    }
}
