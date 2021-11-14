#include "strings/z-function.hpp"

#include <gtest/gtest.h>

TEST(ZFunctionTest, Test1) {
    std::string s = "abcbcba";
    ZFunction z(s);
    std::vector<int> correct = {7, 0, 0, 0, 0, 0, 1};
    ASSERT_EQ(z, correct) << "Incorrect size";
    for (int i = 0; i < (int) z.size(); i++) {
        ASSERT_EQ(z[i], correct[i]) << "Incorrect at position " << i;
    }
}
