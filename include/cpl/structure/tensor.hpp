#ifndef CPL_STRUCTURES_TENSOR_H_
#define CPL_STRUCTURES_TENSOR_H_

#include <array>
#include <cassert>
#include <vector>

template <typename T, int D>
class Tensor : std::vector<T> {
private:
    std::array<int, D> shape;

public:
    Tensor(std::array<int, D> shape_, T val_) : shape(shape_) {
        int size = 1;
        for (int d = 0; d < D; d++) {
            size *= shape[d];
        }
        this->resize(size);
        std::fill(this->begin(), this->end(), val_);
    }

    Tensor(std::array<int, D> shape_) : Tensor(shape_, T()) {}

    int flatten_idx(const std::array<int, D>& idx) const {
        int res = 0;
        int m = 1;
        for (int d = D - 1; d > -1; d--) {
            assert(0 <= idx[d] && idx[d] < shape[d]);
            res += idx[d] * m;
            m *= shape[d];
        }
        return res;
    }

    T& operator[](std::array<int, D> idx) {
        return (*this).at(flatten_idx(idx));
    }

    const T& operator[](std::array<int, D> idx) const {
        return *this[flatten_idx(idx)];
    }
};

#endif  // CPL_STRUCTURES_TENSOR_H_
