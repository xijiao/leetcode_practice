/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

// @lc code=start
class Solution {
 public:
  vector<int> constructRectangle(int area) {
    for (int w = pow(area, 0.5); w > 0; --w) {
      if (area % w == 0) {
        return {area / w, w};
      }
    }
    return {area, 1};
  }
};
// @lc code=end
