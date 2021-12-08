/*
 * @lc app=leetcode id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int ans = 1, curlen = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ans = max(ans, ++curlen);
      } else {
        curlen = 1;
      }
    }
    return ans;
  }
};
// @lc code=end
