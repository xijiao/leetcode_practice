/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    if (s.size() != goal.size() || s.size() < 2) return false;
    vector<int> count(26, 0), diff;
    int maxcount = 0;
    for (int i = 0; i < s.size(); ++i) {
      maxcount = max(maxcount, ++count[s[i] - 'a']);
      if (s[i] != goal[i]) {
        diff.push_back(i);
        if (diff.size() > 2) return false;
      }
    }
    return (diff.size() == 2 && s[diff[0]] == goal[diff[1]] &&
            s[diff[1]] == goal[diff[0]]) ||
           (diff.size() == 0 && maxcount >= 2);
  }
};
// @lc code=end
