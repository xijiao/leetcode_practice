/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
class Solution {
 public:
  int findSubstringInWraproundString(string p) {
    vector<int> count(26);
    char pre = 0;
    int maxLen = 0;
    for (char c : p) {
      if (c - 'a' == (pre + 1 - 'a') % 26) {
        maxLen++;
      } else {
        maxLen = 1;
      }
      pre = c;
      count[c - 'a'] = max(count[c - 'a'], maxLen);
    }
    int ans = 0;
    for (int v : count) ans += v;
    return ans;
  }
};
// @lc code=end
