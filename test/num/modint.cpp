#include "num/modint.hpp"

#include <gtest/gtest.h>

TEST(ModIntTest, ModIntAddIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(5) + 4, ModInt(9));
}

TEST(ModIntTest, ModIntAddIntTest2) {
    const int mod = 5;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(6) + 7, ModInt(3));
}

TEST(ModIntTest, ModIntAddModIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(5) + ModInt(4), ModInt(9));
}

TEST(ModIntTest, ModIntAddModIntTest2) {
    const int mod = 5;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(6) + ModInt(7), ModInt(3));
}

TEST(ModIntTest, ModIntSubtractIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(7) - 4, ModInt(3));
}

TEST(ModIntTest, ModIntSubtractIntTest2) {
    const int mod = 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(21) - 5, ModInt(2));
}

TEST(ModIntTest, ModIntSubtractModIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(7) - ModInt(4), ModInt(3));
}

TEST(ModIntTest, ModIntSubtractModIntTest2) {
    const int mod = 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(21) - ModInt(5), ModInt(2));
}

TEST(ModIntTest, ModIntMultiplyIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(21) * 17, ModInt(357));
}

TEST(ModIntTest, ModIntMultiplyIntTest2) {
    const int mod = 11;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(21) * 17, ModInt(5));
}

TEST(ModIntTest, ModIntMultiplyModIntTest1) {
    const int mod = 1e9 + 7;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(21) * ModInt(17), ModInt(357));
}

TEST(ModIntTest, ModIntMultiplyModIntTest2) {
    const int mod = 11;
    using ModInt = ModInt<mod, int>;
    ASSERT_EQ(ModInt(21) * ModInt(17), ModInt(5));
}
