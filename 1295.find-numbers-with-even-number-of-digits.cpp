/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (int n : nums) {
            int count = 0;
            for (; n; n /= 10, count++);
            if (count % 2 == 0) res++;
        }
        return res;
    }
};
// @lc code=end

