#ifndef CPL_NUM_MODNUM_H
#define CPL_NUM_MODNUM_H

#include <iostream>
#include <stdint.h>

template <int md, typename T = int>
struct Modnum {
    T val;

    T normalize(int64_t x) {
        if (x < -md || x >= md) x %= md;
        if (x < 0) x += md;
        return x;
    }

    Modnum(T val_ = 0) : val(normalize(val_)) {}

    Modnum& operator+=(Modnum o) {
        if ((val += o.val) >= md) val -= md;
        return *this;
    }

    Modnum& operator-=(const Modnum& o) {
        if ((val -= o.val) < 0) val += md;
        return *this;
    }

    Modnum& operator*=(const Modnum& o) {
        val *= o.val;
        val %= md;
        return *this;
    }

    Modnum& operator<<(int by) {
        val <<= by;
        return *this;
    }

    Modnum& operator>>(int by) {
        val >>= by;
        return *this;
    }

    Modnum operator+(const Modnum& o) const { return Modnum(val) += o; }
    Modnum operator-(const Modnum& o) const { return Modnum(val) -= o; }
    Modnum operator*(const Modnum& o) const { return Modnum(val) *= o; }

    bool operator==(const Modnum& o) const { return val == o.val; }

    friend std::istream& operator>>(std::istream& is, const Modnum& obj) {
        return is >> obj.val;
    }

    friend std::ostream& operator<<(std::ostream& os, const Modnum& obj) {
        return os << obj.val;
    }
};

#endif  // CPL_NUM_MODNUM_H
