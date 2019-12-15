/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start

class Solution {
public:
    int reverse(int x) {
        bool negative = false;
        if (x == INT_MIN) return 0;
        if (x < 0) {
            x = -x;
            negative = true;
        }

        int64_t ret = 0;
        for (; x > 0; x /= 10)
        {
            ret *= 10;
            ret += x % 10;
        }
        ret = ret * (negative ? -1 : 1);
        if (ret < INT_MIN || ret > INT_MAX) {
            return 0;
        }
        return ret;
    }
};
// @lc code=end

