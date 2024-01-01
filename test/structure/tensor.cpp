#include "structures/tensor.hpp"

#include <gtest/gtest.h>
#include <random>

TEST(TensorTest, Test1) {
    std::array<int, 3> shape = {5, 7, 11};
    std::mt19937 rng;
    std::vector<std::vector<std::vector<int>>> v(
        shape[0],
        std::vector<std::vector<int>>(shape[1], std::vector<int>(shape[2])));
    Tensor<int, 3> t(shape);
    for (int i0 = 0; i0 < shape[0]; i0++) {
        for (int i1 = 0; i1 < shape[1]; i1++) {
            for (int i2 = 0; i2 < shape[2]; i2++) {
                int val = rng();
                v[i0][i1][i2] = val;
                t[{i0, i1, i2}] = val;
            }
        }
    }

    for (int i0 = 0; i0 < shape[0]; i0++) {
        for (int i1 = 0; i1 < shape[1]; i1++) {
            for (int i2 = 0; i2 < shape[2]; i2++) {
                int x = v[i0][i1][i2];
                int y = t[{i0, i1, i2}];
                ASSERT_EQ(x, y);
            }
        }
    }
}
