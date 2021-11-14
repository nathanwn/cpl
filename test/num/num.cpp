#include "num/num.hpp"

#include "num/modnum.hpp"
#include <gtest/gtest.h>

TEST(PowerTest, Test1) { ASSERT_EQ(power(Modnum<5>(2), 3).val, 3); }
