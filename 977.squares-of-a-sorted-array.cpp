/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    for (int& n : nums) n = n * n;
    vector<int> ans(nums.size());
    int index = nums.size() - 1;
    for (int l = 0, r = nums.size() - 1; l <= r;) {
      if (nums[r] >= nums[l]) {
        ans[index--] = nums[r--];
      } else {
        ans[index--] = nums[l++];
      }
    }
    return ans;
  }
};
// @lc code=end
