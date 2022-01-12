#include "num/num.hpp"

#include "num/modnum.hpp"
#include <gtest/gtest.h>

TEST(PowerTest, Test1) { ASSERT_EQ(power(ModNum<5, int>(2), 3)(), 3); }
