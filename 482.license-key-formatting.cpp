/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

// @lc code=start
class Solution {
 public:
  string licenseKeyFormatting(string s, int k) {
    string ans;
    ans.reserve(s.size());
    int count = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '-') continue;
      if (count > 0 && count % k == 0) {
        ans.push_back('-');
      }
      ans.push_back(toupper(s[i]));
      count++;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
