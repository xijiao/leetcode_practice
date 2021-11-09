/*
 * @lc app=leetcode id=885 lang=cpp
 *
 * [885] Spiral Matrix III
 */

// @lc code=start
class Solution {
  static constexpr int DIRS[][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

 public:
  vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                      int cStart) {
    vector<vector<int>> res;
    int r = rStart, c = cStart;
    res.push_back({r, c});
    if (rows * cols == 1) return res;
    for (int layer = 2;; layer += 2) {
      for (int i = 0; i < 4; i++) {
        if (i == 0) {
          r--;
          c++;
        }
        for (int j = 0; j < layer; j++) {
          c += DIRS[i][0];
          r += DIRS[i][1];
          if (isInBoard(rows, cols, r, c)) {
            res.push_back({r, c});
            if (res.size() == rows * cols) return res;
          }
        }
      }
    }
    return res;
  }

  bool isInBoard(int rows, int cols, int r, int c) {
    return r >= 0 && c >= 0 && r < rows && c < cols;
  }
};
// @lc code=end
