/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        if (n == 0) return 0;
        int sum = 0;
        int product = 1;
        for (int v = n ; v; v /= 10) {
            sum += (v % 10);
            product *= (v % 10);
        }
        return product - sum;
    }
};
// @lc code=end

