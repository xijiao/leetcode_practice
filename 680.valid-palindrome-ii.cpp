/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
 public:
  bool validPalindrome(string s) {
    for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
      if (s[l] == s[r]) continue;
      return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
    }
    return true;
  }

  bool isPalindrome(string& s, int l, int r) {
    for (; l < r; ++l, --r) {
      if (s[l] != s[r]) return false;
    }
    return true;
  }
};
// @lc code=end
