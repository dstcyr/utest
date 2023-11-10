#pragma once
#include <string>
#include <vector>
#include <sstream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

class UTest
{
public:
    UTest(const std::string& name);
    virtual void Run() = 0;
    bool HasPasssed() const;
    const std::string& GetName() const;
    const std::string& GetErrorMsg() const;

protected:
    template<typename T> void AssertEqual(T expected, T actual);
    template<typename T> void AssertNotEqual(T expected, T actual);
    void AssertTrue(bool expected);
    void AssertFalse(bool expected);

private:
    std::string m_Name;
    std::string m_ErrorMessage;
    bool m_Passed;
};

template<typename T>
void UTest::AssertEqual(T expected, T actual)
{
    m_Passed = (expected == actual);
    if (!m_Passed)
    {
        std::stringstream ss;
        ss << "Expected: " << expected << ", Actual : " << actual;
        m_ErrorMessage = ss.str();
    }
}

template<typename T>
void UTest::AssertNotEqual(T expected, T actual)
{
    m_Passed = (expected != actual);
    if (!m_Passed)
    {
        std::stringstream ss;
        ss << "Expected: " << expected << ", Actual: " << actual;
        m_ErrorMessage = ss.str();
    }
}

class UTestRunner
{
public:
    static UTestRunner& Get();
    void Run();

private:
    friend class UTest;
    std::vector<UTest*> m_Tests;
};

#define TEST(testName) \
class testName : public UTest { \
public: \
    testName() : UTest(#testName) {} \
    void Run() override; \
}; \
testName testName##_inst; \
void testName::Run()
