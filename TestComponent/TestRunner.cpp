#include "pch.h"
#include "TestRunner.h"
#include "TestRunner.g.cpp"
#include "..\Tests.h"

namespace winrt::TestComponent::implementation
{
    void TestRunner::TestCallee(ITests const& tests)
    {
        RunTests(tests);
    }

    uint32_t TestRunner::TestCaller(TestHandler const& caller)
    {
        auto tests = make_self<Tests>();
        caller(*tests);
        return tests->Percentage();
    }
}
