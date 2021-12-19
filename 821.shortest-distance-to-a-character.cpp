/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    int n = s.size();
    vector<int> ans(n, INT_MAX);
    for (int cindex = -1, i = 0; i < n; ++i) {
      if (s[i] == c) cindex = i;
      if (cindex == -1) continue;
      ans[i] = min(ans[i], i - cindex);
    }
    for (int cindex = -1, i = n - 1; i >= 0; --i) {
      if (s[i] == c) cindex = i;
      if (cindex == -1) continue;
      ans[i] = min(ans[i], cindex - i);
    }
    return ans;
  }
};
// @lc code=end
