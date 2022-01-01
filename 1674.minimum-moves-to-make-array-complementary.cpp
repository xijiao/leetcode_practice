/*
 * @lc app=leetcode id=1674 lang=cpp
 *
 * [1674] Minimum Moves to Make Array Complementary
 */

// @lc code=start
class Solution {
 public:
  int minMoves(vector<int>& nums, int limit) {
    vector<int> dp(limit * 2 + 2, 0);
    int n = nums.size(), ans = n, cur = n;
    for (int i = 0; i < n / 2; ++i) {
      int a = nums[i], b = nums[n - i - 1];
      --dp[min(a, b) + 1];
      --dp[a + b];
      ++dp[a + b + 1];
      ++dp[max(a, b) + limit + 1];
    }
    for (int i = 0; i <= limit * 2; ++i) {
      cur += dp[i];
      // cout << i << " " << dp[i] << " " << cur << endl;
      ans = min(ans, cur);
    }
    return ans;
  }
};
// @lc code=end
