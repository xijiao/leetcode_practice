/*
 * @lc app=leetcode id=1816 lang=cpp
 *
 * [1816] Truncate Sentence
 */

// @lc code=start
class Solution {
 public:
  string truncateSentence(string s, int k) {
    for (int i = 0, count = 0; i < s.size(); i++) {
      if (s[i] == ' ' && ++count == k) {
        return s.substr(0, i);
      }
    }
    return s;
  }
};
// @lc code=end
