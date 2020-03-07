/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int num: nums) {
            sum += num;
        }
        int n = nums.size();
        return (n + 1) * n / 2 - sum;
    }
};
// @lc code=end

