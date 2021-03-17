/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int t1 = 1, t2 = 2;
        for (int i = 3; i <= n; i++) {
            int t3 = t1 + t2;
            t1 = t2;
            t2 = t3;
        }
        return t2;
    }
};
// @lc code=end

