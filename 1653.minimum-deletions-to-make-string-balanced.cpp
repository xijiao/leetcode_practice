/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution {
 public:
  int minimumDeletions(string s) {
    int n = s.size();
    int bcount = 0;
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        dp[i + 1] = min(dp[i] + 1, bcount);
      } else {
        dp[i + 1] = dp[i];
        bcount++;
      }
    }
    return dp[n];
  }
};
// @lc code=end
