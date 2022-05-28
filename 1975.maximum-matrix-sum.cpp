/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
class Solution {
 public:
  long long maxMatrixSum(vector<vector<int>>& matrix) {
    int abstotal = 0, absmin = INT_MAX, negativecount = 0;
    for (auto& row : matrix) {
      for (auto& cell : row) {
        abstotal += abs(cell);
        absmin = min(absmin, abs(cell));
        negativecount += (cell < 0 ? 1 : 0);
      }
    }
    if (negativecount % 2 == 1) {
      return abstotal - absmin * 2;
    } else {
      return abstotal;
    }
  }
};
// @lc code=end
