/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    for (int l = 0, r = nums.size() - 1; l < r;) {
      if (nums[l] % 2 == 0)
        ++l;
      else if (nums[r] % 2 == 1)
        --r;
      else
        swap(nums[l++], nums[r--]);
    }
    return nums;
  }
};
// @lc code=end
