/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

// @lc code=start
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
      int m = matrix.size(), n = matrix[0].size();
      for (int row = 0; row < m - 1; ++row) {
        for (int i = 0; i < m - row - 1 && i < n - 1; ++i) {
          if (matrix[row + i][i] != matrix[row + i + 1][i + 1]) return false;
        }
      }
      for (int col = 1; col < n - 1; ++col) {
        for (int i = 0; i < n - col - 1 && i < m - 1; ++i) {
          if (matrix[i][col + i] != matrix[i + 1][col + i + 1]) return false;
        }
      }
      return true;
    }
};
// @lc code=end

