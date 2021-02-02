#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "StringCalculator.hpp"

using namespace ::testing;
int main(int argc, char **argv)
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Test, splitString) {
    auto result = splitString("5,5", ",");
    EXPECT_EQ(2, result.size());
    for (auto digit: result) {
        EXPECT_EQ("5", digit);
    }
    result = splitString("111,111", ",");
    EXPECT_EQ(2, result.size());
    for (auto digit: result) {
        EXPECT_EQ("111", digit);
    }
}

TEST(Test, twoNumbersAdd) {
    EXPECT_EQ(10, add("5,5"));
    EXPECT_EQ(4721, add("3490,1231"));
}