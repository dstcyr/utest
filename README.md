# UTest
Simple and easy-to-use testing library in C++



## Usage samples



Declare a test

```C++
#if defined(USING_UTEST)

#include "UTest.h"
#include "Sandbox.h"

TEST(TestSandbox1)
{
    Sandbox sb;
    int result = sb.Add(2, 2);
    AssertEqual(4, result);
}

#endif
```



Run the tests

```C++
int main()
{
#if defined(USING_UTEST)
    UTestRunner::Get().Run();
#endif

    return 0;
}
```

