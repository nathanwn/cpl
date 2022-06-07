#ifndef CPL_NUM_NUM
#define CPL_NUM_NUM

#include <stdint.h>

namespace cpl {

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

template <typename T>
int signum(T val) {
    return (val > T(0)) - (val < T(0));
}

/**
 * Euler's Totient Function
 * Time complexity: O(sqrt(n))
 **/
inline int etf(int n) {
    int phi = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {  // i is a prime factor of n
            while (n % i == 0) n /= i;
            phi -= phi / i;
        }
    }
    if (n > 1) {  // n is prime
        phi -= phi / n;
    }
    return phi;
}

}  // namespace cpl

#endif  // CPL_NUM_NUM
