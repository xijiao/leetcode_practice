/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

// @lc code=start
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
      int line = 1, width = 0;
      for (char c : s) {
        int w = widths[c - 'a'];
        if (width + w > 100) {
          ++line;
          width = 0;
        }
        width += w;
      }
      return {line, width};
    }
};
// @lc code=end

