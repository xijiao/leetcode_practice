/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

// @lc code=start
class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int min1 = min(nums[0], nums[1]), max1 = max(nums[0], nums[1]),
        min2 = nums[0] * nums[1], max2 = nums[0] * nums[1], ans = INT_MIN;
    for (int i = 2; i < nums.size(); i++) {
      ans = max(ans, max(nums[i] * min2, nums[i] * max2));
      min2 = min(min2, min(nums[i] * min1, nums[i] * max1));
      max2 = max(max2, max(nums[i] * min1, nums[i] * max1));
      min1 = min(min1, nums[i]);
      max1 = max(max1, nums[i]);
    }
    return ans;
  }
};
// @lc code=end
