/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0, r = pow(c, 0.5);
        while (l <= r) {
            long long v = l * l + r * r;
            if (v == c) return true;
            else if (v < c) l ++;
            else r --;
        }
        return false;
    }
};
// @lc code=end

