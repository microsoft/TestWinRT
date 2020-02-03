#include "pch.h"

using namespace winrt;
using namespace TestComponent;

int main()
{
    try
    {
        TestRunner::TestSelf();

        ITests tests = TestRunner::MakeTests();
        assert(tests.Percentage() == 0);
        tests.Simple();
        assert(tests.Percentage() > 0);

        puts("Test passed!");
    }
    catch (hresult_error const& e)
    {
        printf("Test failed: %ls\n", e.message().c_str());
    }
}
