# utest
Simple and easy-to-use testing library in C++



## Usage samples



Declare a test

```C++
#if USE_TESTS

TEST(TestSomethingInSandbox)
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
#if USE_TESTS
    UTestRunner::Get().Run();
#endif
    return 0;
}
```

