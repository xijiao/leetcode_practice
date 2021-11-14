/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
 public:
  int cherryPickup(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<vector<int>>> dp(
        rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
    return dfs(grid, rows, cols, 0, 0, cols - 1, dp);
  }

  int dfs(vector<vector<int>>& grid, int rows, int cols, int row, int i, int j,
          vector<vector<vector<int>>>& dp) {
    if (row == rows) return 0;
    if (dp[row][i][j] != -1) return dp[row][i][j];
    int res = 0;
    for (int p = max(0, i - 1); p <= min(cols - 1, i + 1); p++) {
      for (int q = max(0, j - 1); q <= min(cols - 1, j + 1); q++) {
        res = max(res, dfs(grid, rows, cols, row + 1, p, q, dp));
      }
    }
    res += (grid[row][i] + (i != j ? grid[row][j] : 0));
    return dp[row][i][j] = res;
  }
};
// @lc code=end
