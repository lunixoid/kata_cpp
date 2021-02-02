#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "StringCalculator.hpp"

using namespace ::testing;
int main(int argc, char **argv)
{
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Test, twoNumbersAdd) {
    EXPECT_EQ(10, Add("5,5"));
}

TEST(Test, linkingTest) {
    bool link = true;
    EXPECT_TRUE(link);
}