/*
 * @lc app=leetcode id=1401 lang=cpp
 *
 * [1401] Circle and Rectangle Overlapping
 */

// @lc code=start
class Solution {
 public:
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1,
                    int x2, int y2) {
    return isPointInCicle(radius, x_center, y_center, x1, y1) ||
           isPointInCicle(radius, x_center, y_center, x1, y2) ||
           isPointInCicle(radius, x_center, y_center, x2, y1) ||
           isPointInCicle(radius, x_center, y_center, x2, y2) ||
           isLineCrossCicle(radius, x_center, y_center, x1, y1, x1, y2) ||
           isLineCrossCicle(radius, x_center, y_center, x1, y1, x2, y1) ||
           isLineCrossCicle(radius, x_center, y_center, x2, y1, x2, y2) ||
           isLineCrossCicle(radius, x_center, y_center, x2, y2, x1, y2) ||
           isPointInRactangle(x_center, y_center, x1, y1, x2, y2);
  }
  bool isPointInCicle(int radius, int x_center, int y_center, int x, int y) {
    return (x - x_center) * (x - x_center) + (y - y_center) * (y - y_center) <=
           radius * radius;
  }
  bool isLineCrossCicle(int radius, int x_center, int y_center, int x1, int y1,
                        int x2, int y2) {
    // Only consider line parallel to axis
    if (x1 == x2) {
      if (y1 > y2) swap(y1, y2);
      return abs(x_center - x1) <= radius && y_center >= y1 && y_center <= y2;
    } else {
      if (x1 > x2) swap(x1, x2);
      return abs(y_center - y1) <= radius && x_center >= x1 && x_center <= x2;
    }
  }
  bool isPointInRactangle(int x, int y, int x1, int y1, int x2, int y2) {
    return (x >= x1 && x <= x2 && y >= y1 && y <= y2);
  }
};
// @lc code=end
