/*
 * @lc app=leetcode id=661 lang=cpp
 *
 * [661] Image Smoother
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size(), n = img[0].size();
    vector<vector<int>> ans(m, vector<int>(n));
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        int sum = 0;
        int count = 0;
        for (int i = max(0, r - 1); i <= min(m - 1, r + 1); ++i) {
          for (int j = max(0, c - 1); j <= min(n - 1, c + 1); ++j) {
            sum += img[i][j];
            ++count;
          }
        }
        ans[r][c] = sum / count;
      }
    }
    return ans;
  }
};
// @lc code=end
