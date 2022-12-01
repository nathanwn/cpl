#ifndef CPL_NUM_BIGNUM_H
#define CPL_NUM_BIGNUM_H

#include "num.hpp"
#include <stdint.h>
#include <string>
#include <vector>

namespace cpl {

template <int BASE = int(1e9)>
class BigInt : public std::vector<int> {
public:
    BigInt() : sign_(0) {}
    BigInt(int64_t v) { *this = v; }
    BigInt(const std::string& s) { Parse(s); }

    int Signum() const { return sign_; }
    void SetSign(int sign) { sign_ = sign; }
    void FlipSign() { sign_ = -sign_; }
    void Trim() {
        while (!empty() && !back()) pop_back();
        if (empty()) sign_ = 1;
    }

    bool IsZero() const { return empty() || (size() == 1 && (*this)[0] == 0); }

    BigInt& operator=(int64_t v) {
        sign_ = 1;
        if (v < 0) {
            sign_ = -1;
            v = -v;
        }
        clear();
        while (v > 0) {
            push_back(v % BASE);
            v /= BASE;
        }
        return *this;
    }

    BigInt& operator+=(const BigInt& that) {
        if (Signum() == that.Signum()) {
            AbsAdd(that);
        } else {
            if (AbsCmp(*this, that) >= 0) {
                AbsSub(that);
            } else {
                BigInt that2 = that;
                std::swap(*this, that2);
                AbsSub(that2);
            }
        }
        return *this;
    }

    BigInt& operator-=(const BigInt& that) {
        if (Signum() == that.Signum()) {
            if (AbsCmp(*this, that) >= 0) {
                AbsSub(that);
            } else {
                BigInt that2 = that;
                std::swap(*this, that2);
                AbsSub(that2);
                FlipSign();
            }
        } else {
            AbsAdd(that);
        }
        return *this;
    }

    BigInt& operator*=(const BigInt& that) {
        BigInt res;
        res.SetSign(Signum() * that.Signum());
        res.resize(size() + that.size());
        for (size_t i = 0; i < size(); ++i) {
            if (!(*this)[i]) continue;
            int carry = 0;
            for (size_t j = 0; j < that.size() || carry; ++j) {
                int64_t cur =
                    res[i + j] +
                    1LL * (*this)[i] * (j < (int)that.size()) * that[j] + carry;
                carry = cur / BASE;
                res[i + j] = cur % BASE;
            }
        }
        res.Trim();
        *this = res;
        return *this;
    }

    bool operator<(const BigInt& that) const {
        if (Signum() != that.Signum()) {
            return Signum() < that.Signum();
        }
        int sign = Signum();
        if (size() != that.size()) {
            return sign * size() < sign * that.size();
        }
        return sign * (AbsCmp(*this, that)) == -1;
    }

    // pre-increment operator
    BigInt& operator++() { return *this += 1; }

    // post-increment operator
    BigInt operator++(int) {
        BigInt tmp = *this;
        ++*this;
        return tmp;
    }

    // pre-decrement operator
    BigInt& operator--() { return *this -= 1; }

    // post-increment operator
    BigInt operator--(int) {
        BigInt tmp = *this;
        --*this;
        return tmp;
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    BigInt& operator+=(V val) {
        return *this += BigInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    BigInt& operator-=(V val) {
        return *this -= BigInt(val);
    }

    template <typename V, typename = typename std::enable_if<
                              std::is_integral<V>::value>::type>
    BigInt& operator*=(V val) {
        return *this *= BigInt(val);
    }

    bool operator>(const BigInt& that) const { return that < *this; }
    bool operator<=(const BigInt& that) const { return !(*this > that); }
    bool operator>=(const BigInt& that) const { return !(*this < that); }
    bool operator==(const BigInt& that) const {
        return !(*this < that || *this > that);
    }
    bool operator!=(const BigInt& that) const { return !(*this == that); }

private:
    int sign_;

    void Parse(const std::string& s) {
        sign_ = 1;
        clear();
        size_t msd_pos = 0;

        while (msd_pos < s.size() && (s[msd_pos] == '-' || s[msd_pos] == '+')) {
            if (s[msd_pos] == '-') FlipSign();
            ++msd_pos;
        }

        constexpr size_t BASE_LENGTH = std::to_string(BASE).length();

        for (size_t i = s.size() - 1; i > msd_pos; i -= BASE_LENGTH) {
            int d = 0;
            for (int j = std::max(msd_pos, i - BASE_LENGTH + 1); j <= i; ++j) {
                d = d * 10 + s[j] - '0';
            }
            push_back(d);
        }

        Trim();
    }

    void AbsAdd(const BigInt& that) {
        int len = std::max(size(), that.size());
        resize(len, 0);

        int carry = 0;
        for (size_t i = 0; i < len || carry; ++i) {
            if (i == size()) push_back(0);
            (*this)[i] += carry + (i < that.size()) * that[i];
            carry = (*this)[i] >= BASE;
            if (carry) (*this)[i] -= BASE;
        }
    }

    void AbsSub(const BigInt& that) {
        int carry = 0;
        for (size_t i = 0; i < that.size() || carry; ++i) {
            (*this)[i] -= carry + (i < that.size()) * that[i];
            carry = (*this)[i] < 0;
            if (carry) (*this)[i] += BASE;
        }
        Trim();
    }

    friend int AbsCmp(const BigInt& lhs, const BigInt& rhs) {
        if (lhs.size() != rhs.size()) {
            return lhs.size() < rhs.size() ? -1 : 1;
        }
        for (size_t i = lhs.size(); i > -1; --i) {
            if (lhs[i] != rhs[i]) {
                return lhs[i] < rhs[i] ? -1 : 1;
            }
        }
        return 0;
    }
};

}  // namespace cpl

#endif  // CPL_NUM_BIGNUM_H
