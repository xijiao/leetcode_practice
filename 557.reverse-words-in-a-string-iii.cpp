/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int start = 0, n = s.size();
    for (int i = 0; i < n; ++i) {
      if (s[i] == ' ') {
        reverse(s.begin() + start, s.begin() + i);
        start = i + 1;
      }
    }
    reverse(s.begin() + start, s.end());
    return s;
  }
};
// @lc code=end
