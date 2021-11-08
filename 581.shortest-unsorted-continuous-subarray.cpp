/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size(), l = -1, r = -1, curMax = nums[0], curMin = nums[n - 1];
    for (int i = 0; i < n; i++) {
      curMax = max(curMax, nums[i]);
      if (nums[i] < curMax) r = i;
    }
    for (int i = n - 1; i >= 0; i--) {
      curMin = min(curMin, nums[i]);
      if (nums[i] > curMin) l = i;
    }
    return l != -1 ? r - l + 1 : 0;
  }
};
// @lc code=end
