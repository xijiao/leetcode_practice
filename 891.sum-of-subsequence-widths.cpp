/*
 * @lc app=leetcode id=891 lang=cpp
 *
 * [891] Sum of Subsequence Widths
 */

// @lc code=start
class Solution {
 public:
  int sumSubseqWidths(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    const int MOD = 1e9 + 7, n = nums.size();
    long res = 0, c = 1;
    for (int i = 0; i < n; i++, c = c * 2 % MOD) {
      res = (res + nums[i] * c - nums[n - i - 1] * c) % MOD;
    }
    res = (res + MOD) % MOD;
    return res;
  }
};
// @lc code=end
