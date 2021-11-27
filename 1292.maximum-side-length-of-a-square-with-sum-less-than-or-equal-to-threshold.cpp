/*
 * @lc app=leetcode id=1292 lang=cpp
 *
 * [1292] Maximum Side Length of a Square with Sum Less than or Equal to
 * Threshold
 */

// @lc code=start
class Solution {
 public:
  int maxSideLength(vector<vector<int>>& mat, int threshold) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> P(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        P[i][j] =
            P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
      }
    }
    for (int k = min(m, n); k >= 1; --k) {
      for (int i = k; i <= m; ++i) {
        for (int j = k; j <= n; ++j) {
          if (P[i][j] - P[i - k][j] - P[i][j - k] + P[i - k][j - k] <=
              threshold) {
            return k;
          }
        }
      }
    }
    return 0;
  }
};
// @lc code=end
