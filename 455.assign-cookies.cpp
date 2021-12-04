/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end(), greater<int>());
    sort(s.begin(), s.end(), greater<int>());
    int ans = 0;
    for (int i = 0, j = 0; i < g.size() && j < s.size();) {
      if (g[i] <= s[j]) {
        ++ans;
        ++i;
        ++j;
      } else {
        ++i;
      }
    }
    return ans;
  }
};
// @lc code=end
