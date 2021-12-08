/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

// @lc code=start
class Solution {
 public:
  int findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int l = 0, r = 0; r < nums.size(); ++r) {
      while (l < r && nums[r] - nums[l] > 1) ++l;
      if (nums[r] - nums[l] == 1) {
        ans = max(ans, r - l + 1);
      }
    }
    return ans;
  }
};
// @lc code=end
