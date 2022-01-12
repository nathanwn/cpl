#include "num/modnum.hpp"

#include <gtest/gtest.h>

TEST(ModNumTest, ModNumAddIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(5) + 4, ModInt(9));
}

TEST(ModNumTest, ModNumAddIntTest2) {
    const int mod = 5;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(6) + 7, ModInt(3));
}

TEST(ModNumTest, ModNumAddModNumTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(5) + ModInt(4), ModInt(9));
}

TEST(ModNumTest, ModNumAddModNumTest2) {
    const int mod = 5;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(6) + ModInt(7), ModInt(3));
}

TEST(ModNumTest, ModNumSubtractIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(7) - 4, ModInt(3));
}

TEST(ModNumTest, ModNumSubtractIntTest2) {
    const int mod = 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(21) - 5, ModInt(2));
}

TEST(ModNumTest, ModNumSubtractModNumTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(7) - ModInt(4), ModInt(3));
}

TEST(ModNumTest, ModNumSubtractModNumTest2) {
    const int mod = 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(21) - ModInt(5), ModInt(2));
}

TEST(ModNumTest, ModNumMultiplyIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(21) * 17, ModInt(357));
}

TEST(ModNumTest, ModNumMultiplyIntTest2) {
    const int mod = 11;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(21) * 17, ModInt(5));
}

TEST(ModNumTest, ModNumMultiplyModNumTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(21) * ModInt(17), ModInt(357));
}

TEST(ModNumTest, ModNumMultiplyModNumTest2) {
    const int mod = 11;
    using ModInt = ModNum<mod, int>;
    ASSERT_EQ(ModInt(21) * ModInt(17), ModInt(5));
}
