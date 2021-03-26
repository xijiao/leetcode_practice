/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 0, b = 0, mul = 1;
        for (; n;) {
            int d = n % 10;
            n /= 10;

            if ((d == 0 || d == 1) && n > 0) {
                a += 2 * mul;
                b += (10 + d - 2) * mul;
                n --;
            } else {
                a += mul;
                b += (d - 1) * mul;
            }
            mul *= 10;
        }
        return {a, b};
    }
};
// @lc code=end

