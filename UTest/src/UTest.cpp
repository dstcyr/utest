#include "UTest.h"
#include "UTestRunner.h"

UTest::UTest(const std::string& name)
    : m_Name(name), m_Passed(false)
{
    UTestRunner::Get().AddTest(this);
}

bool UTest::HasPasssed() const
{
    return m_Passed;
}

const std::string& UTest::GetName() const
{
    return m_Name;
}

void UTest::Success()
{
    m_Passed = true;
}

void UTest::Fail()
{
    m_Passed = false;
}
