/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
class Solution {
 public:
  int strangePrinter(string s) {
    int n = 1;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] != s[i - 1]) {
        s[n++] = s[i];
      }
    }
    s.resize(n);
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (i == j) {
          dp[i][j] = 1;
          continue;
        } else if (i + 1 == j) {
          dp[i][j] = 2;
          continue;
        }
        dp[i][j] = j - i + 1;
        for (int k = i; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
        if (s[i] == s[j]) dp[i][j]--;
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    return dp[0][n - 1];
  }
};
// @lc code=end
