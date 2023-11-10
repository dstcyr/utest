#include "UTest.h"

int main()
{
#if defined(USING_UTEST)
    UTestRunner::Get().Run();
#endif

    return 0;
}
