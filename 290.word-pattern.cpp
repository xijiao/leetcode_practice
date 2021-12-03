/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    unordered_map<int, string> P;
    unordered_set<string> found;
    int start = 0, index = 0;
    while (start < s.size()) {
      if (index >= pattern.size()) return false;
      int pos = s.find(' ', start);
      pos = pos == string::npos ? s.size() : pos;
      string cur = s.substr(start, pos - start);
      int p = pattern[index];
      if (P.count(p) && P[p] != cur) return false;
      if (!P.count(p) && found.count(cur)) return false;
      P[p] = cur;
      found.insert(cur);
      ++index;
      start = pos + 1;
    }
    return index == pattern.size();
  }
};
// @lc code=end
