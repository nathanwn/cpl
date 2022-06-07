#include "num/num.hpp"

#include "num/modint.hpp"
#include <gtest/gtest.h>

TEST(PowerTest, Test1) { ASSERT_EQ(cpl::power(ModInt<5, int>(2), 3)(), 3); }

TEST(SigNumTest, NegativeTest1) { ASSERT_EQ(cpl::signum(-1), -1); }
TEST(SigNumTest, NegativeTest2) { ASSERT_EQ(cpl::signum(-99), -1); }

TEST(SigNumTest, PositiveTest1) { ASSERT_EQ(cpl::signum(1), 1); }
TEST(SigNumTest, PositiveTest2) { ASSERT_EQ(cpl::signum(101), 1); }

TEST(SigNumTest, ZeroTest) { ASSERT_EQ(cpl::signum(0), 0); }

TEST(EtfTest, Test1) { ASSERT_EQ(cpl::etf(123456), 41088); }
