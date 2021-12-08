/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution {
 public:
  int countBinarySubstrings(string s) {
    int preLen = 0, len = 1, ans = 0;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == s[i - 1]) {
        len++;
      } else {
        preLen = len;
        len = 1;
      }
      if (len <= preLen) ans++;
    }
    return ans;
  }
};
// @lc code=end
