/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
class Solution {
  static const int MOD = 1e9 + 7;

 public:
  int numMusicPlaylists(int n, int goal, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(goal + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= goal; j++) {
        dp[i][j] = (long long)dp[i - 1][j - 1] * (n - i + 1) % MOD;
        if (j > k)
          dp[i][j] = (dp[i][j] + (long long)dp[i][j - 1] * (i - k) % MOD) % MOD;
      }
    }
    return dp[n][goal];
  }
};
// @lc code=end
