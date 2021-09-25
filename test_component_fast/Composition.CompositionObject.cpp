#include "pch.h"
#include "Composition.CompositionObject.h"
#include "Composition.CompositionObject.g.cpp"

namespace winrt::test_component_fast::Composition::implementation
{
    CompositionObject::CompositionObject(Composition::Compositor const& compositor) :
        m_compositor(compositor)
    {
    }

    void CompositionObject::Close()
    {
    }
    Compositor CompositionObject::Compositor()
    {
        return m_compositor;
    }
    void CompositionObject::StartAnimationGroup()
    {
    }
    Windows::Foundation::IInspectable CompositionObject::ObjectProperty()
    {
        return _object;
    }
    void CompositionObject::ObjectProperty(Windows::Foundation::IInspectable const& value)
    {
        _object = value;
    }
}
