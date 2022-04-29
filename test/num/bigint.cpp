#include "num/bigint.hpp"

#include <gtest/gtest.h>

using namespace cpl;

TEST(BigIntTest, BigIntPreIncrementTest1) {
    BigInt<> a = 1;
    BigInt<> b = ++a;
    ASSERT_EQ(b, BigInt<>(2));
}

TEST(BigIntTest, BigIntPostIncrementTest1) {
    BigInt<> a = 1;
    BigInt<> b = a++;
    ASSERT_EQ(b, BigInt<>(1));
}

TEST(BigIntTest, BigIntAdditionAssignmentTest1) {
    BigInt<> a = 1;
    BigInt<> b = a += 5;
    a += 3;
    ASSERT_EQ(a, BigInt<>(9));
    ASSERT_EQ(b, BigInt<>(6));
}

TEST(BigIntTest, BigIntSubtractionAssignmentTest1) {
    BigInt<> a = 12;
    BigInt<> b = a -= 5;
    a -= 3;
    ASSERT_EQ(a, BigInt<>(4));
    ASSERT_EQ(b, BigInt<>(7));
}

TEST(BigIntTest, BigIntMultiplicationAssignmentTest1) {
    BigInt<> a = 15;
    BigInt<> b = 17;
    ASSERT_EQ(a *= b, BigInt<>(255));
}
