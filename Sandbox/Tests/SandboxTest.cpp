#include "UTest.h"
#include "Sandbox.h"

TEST(TestSandbox1)
{
    Sandbox sb;
    int result = sb.Add(2, 2);
    AssertEqual(4, result);
}

TEST(TestSandbox2)
{
    Sandbox sb;
    int result = sb.Add(2, 2);
    AssertNotEqual(6, result);
}

TEST(TestSandbox3)
{
    Sandbox sb;
    int result = sb.Add(2, 2);
    AssertTrue(4 == result);
}

TEST(TestSandbox4)
{
    Sandbox sb;
    int result = sb.Add(2, 2);
    AssertFalse(4 != result);
}
