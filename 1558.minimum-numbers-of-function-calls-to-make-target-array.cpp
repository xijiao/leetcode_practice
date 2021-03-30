/*
 * @lc app=leetcode id=1558 lang=cpp
 *
 * [1558] Minimum Numbers of Function Calls to Make Target Array
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        bool allzero = false;
        for (; !allzero;) {
            int steps = 0;
            for (int& n : nums) {
                if (n % 2) {
                    steps++;
                    n--;
                }
            }
            res += steps;
            allzero = true;
            for (int& n : nums) {
                if (!n) continue;
                allzero = false;
                n /= 2;
            }
            if (!allzero) res += 1;
        }
        return res;
    }
};
// @lc code=end

