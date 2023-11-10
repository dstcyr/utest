#include "UTestRunner.h"
#include "UTest.h"
#include "Sandbox.h"

TEST(CanDoAdditions)
{
    Sandbox sandbox;
    ASSERT_EQUAL(4, 2 + 2);
}

int main()
{
    UTestRunner::Get().RunTests();
    return 0;
}
