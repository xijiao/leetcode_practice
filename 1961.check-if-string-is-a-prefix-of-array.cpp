/*
 * @lc app=leetcode id=1961 lang=cpp
 *
 * [1961] Check If String Is a Prefix of Array
 */

// @lc code=start
class Solution {
 public:
  bool isPrefixString(string s, vector<string>& words) {
    int i = 0;
    for (string& word : words) {
      if (i == s.size()) return true;
      if (s.size() - i < word.size()) return false;
      for (int j = 0; j < word.size(); ++i, ++j) {
        if (s[i] != word[j]) return false;
      }
    }
    return i == s.size();
  }
};
// @lc code=end
