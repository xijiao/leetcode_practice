/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == 2) return x*x;
        while (n % 2 == 0) {
            x = x * x;
            n = n / 2;
        }
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return myPow(x * x, n / 2) * x;
    }
};
// @lc code=end

