/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        uint64_t r = (x + 1U) / 2U;
        while (r * r > x) {
            r = (r + x / r) / 2U;
        }
        return r;
    }
};
// @lc code=end

