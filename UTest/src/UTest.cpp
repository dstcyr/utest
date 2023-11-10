#include "UTest.h"

UTest::UTest(const std::string& name)
    : m_Name(name), m_Passed(false)
{
    UTestRunner::Get().m_Tests.push_back(this);
}

bool UTest::HasPasssed() const
{
    return m_Passed;
}

const std::string& UTest::GetName() const
{
    return m_Name;
}

const std::string& UTest::GetErrorMsg() const
{
    return m_ErrorMessage;
}

void UTest::AssertTrue(bool expected)
{
    m_Passed = expected;
    if (!m_Passed)
    {
        m_ErrorMessage = std::string("Expected: true, Actual: false");
    }
}

void UTest::AssertFalse(bool expected)
{
    m_Passed = !expected;
    if (!m_Passed)
    {
        m_ErrorMessage = std::string("Expected: false, Actual: true");
    }
}

UTestRunner& UTestRunner::Get()
{
    static UTestRunner runner;
    return runner;
}

void UTestRunner::Run()
{
    std::stringstream ss;
    ss << "------ Tests started ------" << std::endl;
    OutputDebugStringA(ss.str().c_str());

    int passedTests = 0;
    const int totalTests = (int)m_Tests.size();

    if (totalTests > 0)
    {
        for (const auto& test : m_Tests)
        {
            test->Run();

            ss.str("");
            ss.clear();
            if (test->HasPasssed())
            {
                passedTests++;
            }
            else
            {
                ss << "[TEST FAIL] " << test->GetName() << ": " << test->GetErrorMsg() << std::endl;
                OutputDebugStringA(ss.str().c_str());
            }
        }
    }

    if (passedTests == totalTests)
    {
        ss.str("");
        ss.clear();
        ss << std::endl << "\tCongratulations! All tests passed." << std::endl;
        OutputDebugStringA(ss.str().c_str());
    }

    ss.str("");
    ss.clear();
    int failed = (int)m_Tests.size() - passedTests;
    ss << std::endl << "========== Passed: " << passedTests << ", failed " << failed << " ==========" << std::endl;
    OutputDebugStringA(ss.str().c_str());
}
