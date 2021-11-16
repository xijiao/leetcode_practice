/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    int n = s.size();
    vector<int> first(26, n), last(26);
    for (int i = 0; i < n; i++) {
      first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
      last[s[i] - 'a'] = i;
    }

    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (first[i] >= last[i]) continue;
      res += (unordered_set<int>(s.begin() + first[i] + 1, s.begin() + last[i]))
                 .size();
    }
    return res;
  }
};
// @lc code=end
