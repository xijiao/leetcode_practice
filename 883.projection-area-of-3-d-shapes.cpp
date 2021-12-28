/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

// @lc code=start
class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int xyarea = 0, xzarea = 0, yzarea = 0;
    for (int x = 0; x < m; x++) {
      int maxheight = 0;
      for (int y = 0; y < n; y++) {
        maxheight = max(maxheight, grid[x][y]);
        if (grid[x][y]) xyarea++;
      }
      xzarea += maxheight;
    }
    for (int y = 0; y < n; y++) {
      int maxheight = 0;
      for (int x = 0; x < m; x++) {
        maxheight = max(maxheight, grid[x][y]);
      }
      yzarea += maxheight;
    }
    return xyarea + xzarea + yzarea;
  }
};
// @lc code=end
