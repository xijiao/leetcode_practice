/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
class Solution {
 public:
  string reverseOnlyLetters(string s) {
    for (int l = 0, r = s.size() - 1; l < r;) {
      if (!isalpha(s[l]))
        l++;
      else if (!isalpha(s[r]))
        r--;
      else
        swap(s[l++], s[r--]);
    }
    return s;
  }
};
// @lc code=end
