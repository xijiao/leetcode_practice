/*
 * @lc app=leetcode id=483 lang=cpp
 *
 * [483] Smallest Good Base
 */

// @lc code=start
class Solution {
public:
    string smallestGoodBase(string n) {
        uint64_t N = stoll(n);
        for (int bits = 62; bits > 1; bits--) {
            string res = resolve(N, bits);
            if (res.size()) return res;
        }
        return "";
    }

    string resolve(uint64_t N, int bits) {
        // cout << N << " " << bits << endl;
        uint64_t l = 2;
        uint64_t r = pow(double(N), 1.0 / (bits - 1)) + 1;
        if (bits == 2) r = N; // in case of losing precision
        for (; l <= r;) {
            uint64_t m = (l + r) / 2;
            uint64_t v = 1;
            for (int i = 1; i < bits; i++) {
                v = v * m + 1;
                if (v > N) break;
            }
            // cout << l << " " << r << " " << m << " " << v << endl;
            if (v == N) return to_string(m);
            else if (v > N) r = m - 1;
            else l = m + 1;
        }
        return "";
    }
};
// @lc code=end

