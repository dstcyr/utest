#pragma once
#include <vector>

class UTest;
class UTestRunner
{
public:
    static UTestRunner& Get();
    void RunTests();
    void AddTest(UTest* test);

private:
    std::vector<UTest*> m_Tests;
};
