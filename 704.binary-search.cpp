/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    for (int l = 0, r = nums.size() - 1; l <= r;) {
      int m = (l + r) / 2;
      if (nums[m] > target)
        r = m - 1;
      else if (nums[m] < target)
        l = m + 1;
      else
        return m;
    }
    return -1;
  }
};
// @lc code=end
