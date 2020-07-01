#include "pch.h"
#include "BenchmarkComponent.h"
#include "ClassWithMultipleInterfaces.g.cpp"

namespace winrt::BenchmarkComponent::implementation
{
    ClassWithMultipleInterfaces::ClassWithMultipleInterfaces()
    {
    }

    int32_t ClassWithMultipleInterfaces::IntProperty()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::IntProperty(int32_t val)
    {
    }

    bool ClassWithMultipleInterfaces::BoolProperty()
    {
        return true;
    }

    void ClassWithMultipleInterfaces::BoolProperty(bool val)
    {
    }

    double ClassWithMultipleInterfaces::DoubleProperty()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::DoubleProperty(double val)
    {
    }

    int32_t ClassWithMultipleInterfaces::DefaultIntProperty()
    {
        return 1;
    }

    bool ClassWithMultipleInterfaces::DefaultBoolProperty()
    {
        return false;
    }

    double ClassWithMultipleInterfaces::DefaultDoubleProperty()
    {
        return 1;
    }

    void ClassWithMultipleInterfaces::DefaultIntProperty(int32_t val)
    {
    }

    void ClassWithMultipleInterfaces::DefaultBoolProperty(bool val)
    {
    }

    void ClassWithMultipleInterfaces::DefaultDoubleProperty(double val)
    {
    }
}