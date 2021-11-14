#ifndef CPL_NUM_MODNUM_H
#define CPL_NUM_MODNUM_H

#include <iostream>
#include <stdint.h>

template <int md, typename T = int>
struct ModNum {
    T val;

    T normalize(int64_t x) {
        if (x < -md || x >= md) x %= md;
        if (x < 0) x += md;
        return x;
    }

    ModNum(T val_ = 0) : val(normalize(val_)) {}

    ModNum& operator+=(ModNum o) {
        if ((val += o.val) >= md) val -= md;
        return *this;
    }

    ModNum& operator-=(const ModNum& o) {
        if ((val -= o.val) < 0) val += md;
        return *this;
    }

    ModNum& operator*=(const ModNum& o) {
        val *= o.val;
        val %= md;
        return *this;
    }

    ModNum& operator<<(int by) {
        val <<= by;
        return *this;
    }

    ModNum& operator>>(int by) {
        val >>= by;
        return *this;
    }

    ModNum operator+(const ModNum& o) const { return ModNum(val) += o; }
    ModNum operator-(const ModNum& o) const { return ModNum(val) -= o; }
    ModNum operator*(const ModNum& o) const { return ModNum(val) *= o; }

    bool operator==(const ModNum& o) const { return val == o.val; }

    friend std::istream& operator>>(std::istream& is, const ModNum& obj) {
        return is >> obj.val;
    }

    friend std::ostream& operator<<(std::ostream& os, const ModNum& obj) {
        return os << obj.val;
    }
};

#endif  // CPL_NUM_MODNUM_H
