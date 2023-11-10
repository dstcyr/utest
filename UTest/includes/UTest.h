#pragma once
#include <string>
#include "UTestAssertions.h"

class UTest
{
public:
    UTest(const std::string& name);
    virtual void Run() = 0;
    bool HasPasssed() const;
    const std::string& GetName() const;

protected:
    void Success();
    void Fail();

private:
    std::string m_Name;
    bool m_Passed;
};

#define TEST(testName) \
class testName : public UTest { \
public: \
    testName() : UTest(#testName) {} \
    void Run() override; \
}; \
testName testName##_inst; \
void testName::Run()
