#pragma once
#include "Composition.CompositionObject.g.h"

namespace winrt::test_component_fast::Composition::implementation
{
    struct CompositionObject : CompositionObjectT<CompositionObject>
    {
        CompositionObject(Composition::Compositor const& compositor);

        void Close();
        Composition::Compositor Compositor();
        void StartAnimationGroup();
        Windows::Foundation::IInspectable ObjectProperty();
        void ObjectProperty(Windows::Foundation::IInspectable const& value);

    protected:

        Composition::Compositor m_compositor{ nullptr };
        Windows::Foundation::IInspectable _object;
    };
}
