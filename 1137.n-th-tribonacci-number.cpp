/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if (n <= 1) return n;
        int p1 = 0, p2 = 1, p3 = 1;
        for (int i = 2; i < n; i++) {
            int v = p1 + p2 + p3;
            p1 = p2;
            p2 = p3;
            p3 = v;
        }
        return p3;
    }
};
// @lc code=end

