#include "num/modnum.hpp"
#include <gtest/gtest.h>

TEST(ModNumTest, AddTest1) {
    const int mod = 1e9 + 7;
    using ModInt = Modnum<mod>;
    ASSERT_EQ(ModInt(5) + ModInt(4), ModInt(9));
}

TEST(ModNumTest, AddTest2) {
    const int mod = 5;
    using ModInt = Modnum<mod>;
    ASSERT_EQ(ModInt(6) + ModInt(7), ModInt(3));
}

TEST(ModNumTest, SubtractTest1) {
    const int mod = 1e9 + 7;
    using ModInt = Modnum<mod>;
    ASSERT_EQ(ModInt(7) - ModInt(4), ModInt(3));
}

TEST(ModNumTest, SubtractTest2) {
    const int mod = 7;
    using ModInt = Modnum<mod>;
    ASSERT_EQ(ModInt(21) - ModInt(5), ModInt(2));
}

TEST(ModNumTest, MultiplyTest1) {
    const int mod = 1e9 + 7;
    using ModInt = Modnum<mod>;
    ASSERT_EQ(ModInt(21) * ModInt(17), ModInt(357));
}

TEST(ModNumTest, MultiplyTest2) {
    const int mod = 11;
    using ModInt = Modnum<mod>;
    ASSERT_EQ(ModInt(21) * ModInt(17), ModInt(5));
}

