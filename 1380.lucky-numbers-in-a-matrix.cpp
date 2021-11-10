/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

// @lc code=start
class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    unordered_set<int> found;
    for (int i = 0; i < m; i++) {
      int minValue = matrix[i][0];
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] < minValue) {
          minValue = min(minValue, matrix[i][j]);
        }
      }
      found.insert(minValue);
    }
    vector<int> res;
    for (int j = 0; j < n; j++) {
      int maxValue = matrix[0][j];
      for (int i = 1; i < m; i++) {
        maxValue = max(maxValue, matrix[i][j]);
      }
      if (found.count(maxValue)) {
        res.push_back(maxValue);
      }
    }
    return res;
  }
};
// @lc code=end
