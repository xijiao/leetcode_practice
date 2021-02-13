/*
 * @lc app=leetcode id=869 lang=cpp
 *
 * [869] Reordered Power of 2
 */

// @lc code=start
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        long long digit_count_n = countDigit(N);
        for (int i = 0; i < 32; i++) {
            long long digit_count_i = countDigit(1 << i);
            if (digit_count_n == digit_count_i) {
                return true;
            }
        }
        return false;
    }

    long long countDigit(int num) {
        long long res = 0;
        for (int i = num; i > 0; i /= 10) {
            int v = i % 10;
            res += pow(10, v);
        }
        return res;
    }
};
// @lc code=end

