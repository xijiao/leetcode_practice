/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int l = 0, r = 0;
    for (; r < nums.size(); ++r) {
      if (nums[r]) {
        nums[l++] = nums[r];
      }
    }
    for (; l < nums.size(); ++l) {
      nums[l] = 0;
    }
  }
};
// @lc code=end
