#ifndef CPL_NUM_NUM
#define CPL_NUM_NUM

#include <stdint.h>

template <typename T>
T power(T a, int64_t x) {
    T res = 1;
    while (x > 0) {
        if (x & 1) res *= a;
        a *= a;
        x >>= 1;
    }
    return res;
}

#endif  // CPL_NUM_NUM
