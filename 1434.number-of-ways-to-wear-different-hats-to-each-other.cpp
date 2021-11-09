/*
 * @lc app=leetcode id=1434 lang=cpp
 *
 * [1434] Number of Ways to Wear Different Hats to Each Other
 */

// @lc code=start
class Solution {
 public:
  int numberWays(vector<vector<int>>& hats) {
    int n = hats.size(), maxHat = 0;
    vector<vector<int>> hat2ppl(41, vector<int>());
    for (int p = 0; p < n; p++) {
      for (int h : hats[p]) {
        hat2ppl[h].push_back(p);
        maxHat = max(maxHat, h);
      }
    }
    vector<vector<int>> dp(maxHat + 1, vector<int>(1 << n, -1));
    return dfs(hat2ppl, maxHat, (1 << n) - 1, 1, 0, dp);
  }

  int dfs(vector<vector<int>>& hat2ppl, int maxHat, int allMask, int hat,
          int pplmask, vector<vector<int>>& dp) {
    const int MOD = 1e9 + 7;
    if (pplmask == allMask) return 1;
    if (hat > maxHat) return 0;
    if (dp[hat][pplmask] != -1) return dp[hat][pplmask];

    int ans = dfs(hat2ppl, maxHat, allMask, hat + 1, pplmask, dp) % MOD;
    for (int p : hat2ppl[hat]) {
      if (pplmask & (1 << p)) continue;
      ans = (ans +
             dfs(hat2ppl, maxHat, allMask, hat + 1, pplmask | (1 << p), dp)) %
            MOD;
    }
    return dp[hat][pplmask] = ans;
  }
};
// @lc code=end
