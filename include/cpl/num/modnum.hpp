#ifndef CPL_NUM_MODNUM_H
#define CPL_NUM_MODNUM_H

#include <iostream>
#include <stdint.h>

template <int md, typename T,
          typename = typename std::enable_if<std::is_integral<T>::value>::type>
class ModNum {
    T val_;

    T normalize(int64_t x) {
        if (x < -md || x >= md) x %= md;
        if (x < 0) x += md;
        return x;
    }

public:
    ModNum(T val = 0) : val_(normalize(val)) {}

    T operator()() const { return val_; }

    ModNum& operator+=(const ModNum& o) {
        if ((val_ += o()) >= md) val_ -= md;
        return *this;
    }

    ModNum& operator-=(const ModNum& o) {
        if ((val_ -= o()) < 0) val_ += md;
        return *this;
    }

    ModNum& operator*=(const ModNum& o) {
        val_ =
            normalize(static_cast<int64_t>(val_) * static_cast<int64_t>(o()));
        return *this;
    }

    ModNum& operator<<=(int by) {
        if ((val_ <<= by) >= md) val_ -= md;
        return *this;
    }

    ModNum& operator>>=(int by) {
        val_ >>= by;
        return *this;
    }

    ModNum operator+(const ModNum& o) const { return ModNum(val_) += o; }
    ModNum operator-(const ModNum& o) const { return ModNum(val_) -= o; }
    ModNum operator*(const ModNum& o) const { return ModNum(val_) *= o; }

    bool operator==(const ModNum& o) const { return val_ == o(); }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModNum& operator+=(V val) {
        return *this += ModNum(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModNum& operator-=(V val) {
        return *this -= ModNum(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModNum& operator*=(V val) {
        return *this *= ModNum(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModNum operator+(V val) const {
        return ModNum(val_) += ModNum(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModNum operator-(V val) const {
        return ModNum(val_) -= ModNum(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModNum operator*(V val) const {
        return ModNum(val_) *= ModNum(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    bool operator==(V val) const { return val_ == val; }

    friend std::istream& operator>>(std::istream& is, const ModNum& o) {
        return is >> o();
    }

    friend std::ostream& operator<<(std::ostream& os, const ModNum& o) {
        return os << o();
    }
};

#endif  // CPL_NUM_MODNUM_H
