/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    if (image[sr][sc] == newColor) return image;
    paint(image, sr, sc, image[sr][sc], newColor);
    return image;
  }

  void paint(vector<vector<int>>& image, int sr, int sc, int color,
             int newColor) {
    int m = image.size(), n = image[0].size();
    if (sr < 0 || sr >= m || sc < 0 || sc >= n || image[sr][sc] != color)
      return;
    image[sr][sc] = newColor;
    paint(image, sr + 1, sc, color, newColor);
    paint(image, sr - 1, sc, color, newColor);
    paint(image, sr, sc + 1, color, newColor);
    paint(image, sr, sc - 1, color, newColor);
  }
};
// @lc code=end
