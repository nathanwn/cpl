#include "num/num.hpp"

#include "num/modint.hpp"
#include <gtest/gtest.h>

TEST(PowerTest, IntTest) { ASSERT_EQ(cpl::power(2, 10), 1024); }
TEST(PowerTest, ModIntTest) { ASSERT_EQ(cpl::power(ModInt<5, int>(2), 3)(), 3); }

TEST(SigNumTest, NegativeTest1) { ASSERT_EQ(cpl::sgn(-1), -1); }
TEST(SigNumTest, NegativeTest2) { ASSERT_EQ(cpl::sgn(-99), -1); }

TEST(SigNumTest, PositiveTest1) { ASSERT_EQ(cpl::sgn(1), 1); }
TEST(SigNumTest, PositiveTest2) { ASSERT_EQ(cpl::sgn(101), 1); }

TEST(SigNumTest, ZeroTest) { ASSERT_EQ(cpl::sgn(0), 0); }

TEST(EulerPhi, Test1) { ASSERT_EQ(cpl::euler_phi(123456), 41088); }
