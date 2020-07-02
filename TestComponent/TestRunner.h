#pragma once
#include "TestRunner.g.h"

namespace winrt::TestComponent::implementation
{
    struct TestRunner
    {
        TestRunner() = default;

        static void TestProducer(ITests const& callee);
        static uint32_t TestConsumer(TestHandler const& caller);
        static void TestSelf();
        static ITests MakeTests();
        static Windows::Foundation::Collections::IVector<int32_t> CreateInt32Vector();
        static Windows::Foundation::Collections::IVector<hstring> CreateStringVector();
        static Windows::Foundation::Collections::IVector<Windows::Foundation::IStringable> CreateStringableVector();
    };
}

namespace winrt::TestComponent::factory_implementation
{
    struct TestRunner : TestRunnerT<TestRunner, implementation::TestRunner>
    {
    };
}
