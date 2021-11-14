#ifndef CPL_STRINGS_Z_FUNCTION
#define CPL_STRINGS_Z_FUNCTION

#include <string>
#include <vector>

struct ZFunction : std::vector<int> {
    ZFunction(const std::string& s) : std::vector<int>(s.size(), 0) {
        auto& z = *this;
        int n = z.size();
        z[0] = n;
        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r) {
                z[i] = std::min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
    }
};

#endif  // CPL_STRINGS_Z_FUNCTION
