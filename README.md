# utest
Simple and easy-to-use testing library in C++



## Usage samples



Declare a test

```C++
TEST(TestSomethingInSandbox)
{
    Sandbox sb;
    int result = sb.Add(2, 2);
    AssertEqual(4, result);
}
```



Run the tests

```C++
int main()
{
    UTestRunner::Get().Run();
    return 0;
}
```

