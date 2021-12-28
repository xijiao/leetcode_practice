/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

// @lc code=start
class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    int ans = 0, n = grid.size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] > 0) {
          ans += (grid[i][j] * 4 + 2);
          if (i > 0) {
            ans -= min(grid[i - 1][j], grid[i][j]) * 2;
          }
          if (j > 0) {
            ans -= min(grid[i][j - 1], grid[i][j]) * 2;
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end
