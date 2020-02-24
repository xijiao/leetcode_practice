/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int f1 = 1;
        int f2 = 1;
        for (int i = 1; i < n; i++) {
            int cur = f1 + f2;
            f1 = f2;
            f2 = cur;
        }
        return f2;
    }
};
// @lc code=end

