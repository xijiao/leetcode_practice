/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

// @lc code=start
class Solution {
 public:
  string removeOuterParentheses(string s) {
    stringstream ss;
    for (int i = 0, depth = 0, start = 0; i <= s.size(); i++) {
      if (s[i] == '(')
        depth++;
      else
        depth--;
      if (depth == 0) {
        ss << s.substr(start + 1, i - start - 1);
        start = i + 1;
      }
    }
    return ss.str();
  }
};
// @lc code=end
