/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

// @lc code=start
class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    int maxv = nums[0], minv = nums[0];
    for (int v : nums) {
      maxv = max(maxv, v);
      minv = min(minv, v);
    }
    return max(0, maxv - minv - k * 2);
  }
};
// @lc code=end
