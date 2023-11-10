#include "UTestRunner.h"
#include "UTest.h"
#include <iostream>

UTestRunner& UTestRunner::Get()
{
    static UTestRunner runner;
    return runner;
}

void UTestRunner::RunTests()
{
    int passedTests = 0;
    for (const auto& test : m_Tests)
    {
        std::cout << "Running test: " << test->GetName() << std::endl;
        test->Run();

        if (test->HasPasssed())
        {
            std::cout << "Test passed!" << std::endl;
            passedTests++;
        }
        else
        {
            std::cerr << "Test failed!" << std::endl;
        }

        std::cout << "---------------------" << std::endl;
    }

    std::cout << "Summary: " << passedTests << " out of " << m_Tests.size() << " tests passed." << std::endl;
}

void UTestRunner::AddTest(UTest* test)
{
    m_Tests.push_back(test);
}
