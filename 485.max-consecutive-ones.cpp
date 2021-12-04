/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, curMax = 0;
    for (int n : nums) {
      if (n == 1)
        curMax++;
      else
        curMax = 0;
      ans = max(ans, curMax);
    }
    return ans;
  }
};
// @lc code=end
