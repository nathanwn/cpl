#ifndef CPL_NUM_MODNUM_H
#define CPL_NUM_MODNUM_H

#include <iostream>
#include <stdint.h>

template <int md, typename T,
          typename = typename std::enable_if<std::is_integral<T>::value>::type>
class ModInt {
    T val_;

    T Normalize(int64_t x) {
        if (x < -md || x >= md) x %= md;
        if (x < 0) x += md;
        return x;
    }

public:
    ModInt(T val = 0) : val_(Normalize(val)) {}

    T operator()() const { return val_; }

    ModInt& operator+=(const ModInt& o) {
        if ((val_ += o()) >= md) val_ -= md;
        return *this;
    }

    ModInt& operator-=(const ModInt& o) {
        if ((val_ -= o()) < 0) val_ += md;
        return *this;
    }

    ModInt& operator*=(const ModInt& o) {
        val_ =
            Normalize(static_cast<int64_t>(val_) * static_cast<int64_t>(o()));
        return *this;
    }

    ModInt& operator<<=(int by) {
        if ((val_ <<= by) >= md) val_ -= md;
        return *this;
    }

    ModInt& operator>>=(int by) {
        val_ >>= by;
        return *this;
    }

    // pre-increment operator
    ModInt& operator++() { return *this += 1; }

    // post-increment operator
    ModInt operator++(int) {
        ModInt tmp = *this;
        ++*this;
        return tmp;
    }

    // pre-decrement operator
    ModInt& operator--() { return *this -= 1; }

    // post-increment operator
    ModInt operator--(int) {
        ModInt tmp = *this;
        --*this;
        return tmp;
    }

    ModInt operator+(const ModInt& o) const { return ModInt(val_) += o; }
    ModInt operator-(const ModInt& o) const { return ModInt(val_) -= o; }
    ModInt operator*(const ModInt& o) const { return ModInt(val_) *= o; }

    bool operator==(const ModInt& o) const { return val_ == o(); }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModInt& operator+=(V val) {
        return *this += ModInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModInt& operator-=(V val) {
        return *this -= ModInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModInt& operator*=(V val) {
        return *this *= ModInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModInt operator+(V val) const {
        return ModInt(val_) += ModInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModInt operator-(V val) const {
        return ModInt(val_) -= ModInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    ModInt operator*(V val) const {
        return ModInt(val_) *= ModInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    bool operator==(V val) const {
        return val_ == val;
    }

    friend std::istream& operator>>(std::istream& is, const ModInt& o) {
        return is >> o();
    }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& o) {
        return os << o();
    }
};

#endif  // CPL_NUM_MODNUM_H
