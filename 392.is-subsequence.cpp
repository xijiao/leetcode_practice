/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int l = 0, r = 0;
    for (; l < s.size() && r < t.size();) {
      if (s[l] == t[r]) {
        ++l;
        ++r;
      } else {
        ++r;
      }
    }
    return l == s.size();
  }
};
// @lc code=end
