/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    trytype(s);
    trytype(t);
    return s == t;
  }

  void trytype(string& s) {
    int l = 0, r = 0;
    for (; r < s.size(); ++r) {
      if (s[r] == '#') {
        l = max(0, l - 1);
      } else {
        s[l++] = s[r];
      }
    }
    s.resize(l);
  }
};
// @lc code=end
