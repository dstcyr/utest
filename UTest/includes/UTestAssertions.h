#pragma once
#include <iostream>

#define ASSERT_TRUE(expr)                                           \
    if (!(expr)) {                                                  \
        std::cerr << "Assertion failed: " << #expr << std::endl;    \
        Fail();                                                     \
        return;                                                     \
    }                                                               \
    Success();                                                      \

#define ASSERT_EQUAL(expected, actual){         \
    ASSERT_TRUE((expected) == (actual))}

#define ASSERT_NOT_EQUAL(not_expected, actual){ \
    ASSERT_TRUE((expected) != (actual))}
