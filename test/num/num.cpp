#include "num/num.hpp"

#include "num/modint.hpp"
#include <gtest/gtest.h>

TEST(PowerTest, Test1) { ASSERT_EQ(cpl::Power(ModInt<5, int>(2), 3)(), 3); }

TEST(SigNumTest, NegativeTest1) { ASSERT_EQ(cpl::Signum(-1), -1); }
TEST(SigNumTest, NegativeTest2) { ASSERT_EQ(cpl::Signum(-99), -1); }

TEST(SigNumTest, PositiveTest1) { ASSERT_EQ(cpl::Signum(1), 1); }
TEST(SigNumTest, PositiveTest2) { ASSERT_EQ(cpl::Signum(101), 1); }

TEST(SigNumTest, ZeroTest) { ASSERT_EQ(cpl::Signum(0), 0); }

TEST(EulerPhi, Test1) { ASSERT_EQ(cpl::EulerPhi(123456), 41088); }
