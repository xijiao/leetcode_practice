/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max_sa = nums[0];
        int former_min = min(0, nums[0]);
        int cur = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            cur += nums[i];
            if (cur - former_min > max_sa) {
                max_sa = cur - former_min;
            }
            if (cur < former_min) {
                former_min = cur;
            }
        }

        return max_sa;
    }
};
// @lc code=end

