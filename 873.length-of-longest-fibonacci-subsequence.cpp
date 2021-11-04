/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

// @lc code=start
class Solution {
 public:
  // Time Limit Exceeded
  //   int lenLongestFibSubseq(vector<int>& arr) {
  //     int n = arr.size();
  //     vector<unordered_map<int, int>> dp(n);
  //     int res = 0;
  //     for (int i = 0; i < n; i++) {
  //       for (int j = 0; j < i; j++) {
  //         int prevValue = arr[i] - arr[j];
  //         dp[i][arr[j]] = max(2, dp[i][arr[j]]);
  //         if (dp[j].count(prevValue)) {
  //           dp[i][arr[j]] = max(dp[i][arr[j]], dp[j][prevValue] + 1);
  //         }
  //         res = max(res, dp[i][arr[j]]);
  //       }
  //     }
  //     return res > 2 ? res : 0;
  //   }
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int res = 0;
    for (int i = 2; i < n; i++) {
      int l = 0, r = i - 1;
      while (l < r) {
        if (arr[l] + arr[r] > arr[i]) {
          --r;
        } else if (arr[l] + arr[r] < arr[i]) {
          ++l;
        } else {
          dp[r][i] = dp[l][r] + 1;
          res = max(res, dp[r][i]);
          --r;
          ++l;
        }
      }
    }
    return res == 0 ? 0 : res + 2;
  }
};
// @lc code=end
