/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> preSum(n);
    for (int i = n - 1, sum = 0; i >= 0; --i) {
      preSum[i] = sum;
      sum += nums[i];
    }
    for (int i = 0, sum = 0; i < n; ++i) {
      if (sum == preSum[i]) return i;
      sum += nums[i];
    }
    return -1;
  }
};
// @lc code=end
