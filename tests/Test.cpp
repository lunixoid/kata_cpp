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
    auto result = splitString("5,5");
    EXPECT_EQ(2, result.size());
    for (auto digit: result) {
        EXPECT_EQ("5", digit);
    }

    result = splitString("111,111");
    EXPECT_EQ(2, result.size());
    for (auto digit: result) {
        EXPECT_EQ("111", digit);
    }

    result = splitString("77\n77,77\n77");
    EXPECT_EQ(4, result.size());
    for (auto digit: result) {
        EXPECT_EQ("77", digit);
    }
}

TEST(Test, empty) {
    EXPECT_EQ(0, add(""));
}

TEST(Test, singleNumber) {
    EXPECT_EQ(10, add("10"));
    EXPECT_EQ(4721, add("4721"));
}

TEST(Test, twoNumbers) {
    EXPECT_EQ(10, add("5,5"));
    EXPECT_EQ(4721, add("3490,1231"));
}

TEST(Test, unknownAmoutOfNumbers) {
    EXPECT_EQ(3, add("1,1,1"));
    EXPECT_EQ(8, add("1,1,1,1,1,1,1,1"));
    EXPECT_EQ(1990, add("1000,900,80,10"));
}

TEST(Test, newLineDelimiter) {
    EXPECT_EQ(6, add("1\n2,3"));
    EXPECT_EQ(111, add("100\n10\n1"));
    EXPECT_EQ(781, add("300,1,200\n100,100,40\n40"));
}