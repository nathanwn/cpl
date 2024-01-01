#ifndef CPL_COORDINATE_COMPRESSION
#define CPL_COORDINATE_COMPRESSION

#include <algorithm>
#include <vector>

template <typename T>
std::vector<int> coordinate_compress(const std::vector<T>& a) {
    std::vector<int> b(a.begin(), a.end());

    std::sort(b.begin(), b.end());
    b.resize(std::unique(b.begin(), b.end()) - b.begin());
    std::vector<int> c(a.size());

    for (int i = 0; i < (int) c.size(); i++) {
        c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }

    return c;
}

#endif  // CPL_COORDINATE_COMPRESSION
