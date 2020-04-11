/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);
        int cur = 1;
        for (int i = 0; i < nums.size(); i++) {
            output[i] = cur;
            cur *= nums[i];
        }
        cur = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= cur;
            cur *= nums[i];
        }
        return output;
    }
};
// @lc code=end

