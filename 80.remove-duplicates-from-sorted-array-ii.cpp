/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int count = 0, prenum = 0, precount = 0;
    for (int num : nums) {
      if (num == prenum) {
        precount++;
      } else {
        prenum = num;
        precount = 1;
      }
      if (precount > 2) continue;
      nums[count++] = num;
    }
    return count;
  }
};
// @lc code=end
