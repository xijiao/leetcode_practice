/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

// @lc code=start
class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    double res = 0;
    for (auto& a : points)
      for (auto& b : points)
        for (auto& c : points)
          res = max(res, 0.5 * (a[0] * b[1] + b[0] * c[1] + c[0] * a[1] -
                                a[0] * c[1] - c[0] * b[1] - b[0] * a[1]));
    return res;
  }
};
// @lc code=end
