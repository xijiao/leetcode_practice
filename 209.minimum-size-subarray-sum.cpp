/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = nums.size() + 1;
        int former = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= s) {
                res = min(res, i - former + 1);
                sum -= nums[former++];
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};
// @lc code=end

