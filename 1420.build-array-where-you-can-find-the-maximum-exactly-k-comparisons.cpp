/*
 * @lc app=leetcode id=1420 lang=cpp
 *
 * [1420] Build Array Where You Can Find The Maximum Exactly K Comparisons
 */

// @lc code=start
class Solution {
  static const int MOD = 1e9 + 7;

 public:
  int numOfArrays(int n, int m, int k) {
    vector<vector<vector<int>>> cache(
        n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      res = (res + dp(n, i, k, cache)) % MOD;
    }
    return res;
  }

  int dp(int len, int maxValue, int cost, vector<vector<vector<int>>>& cache) {
    if (cost <= 0 || cost > len || cost > maxValue) return 0;
    if (len == maxValue && len == cost) return 1;
    if (len == 1 && cost == 1) return 1;
    if (maxValue == 1 && cost == 1) return 1;
    if (cache[len][maxValue][cost] != -1) return cache[len][maxValue][cost];
    int ans = (long long)dp(len - 1, maxValue, cost, cache) * maxValue % MOD;
    for (int i = 1; i < maxValue; i++) {
      ans = (ans + dp(len - 1, i, cost - 1, cache)) % MOD;
    }
    return cache[len][maxValue][cost] = ans;
  }
};
// @lc code=end
