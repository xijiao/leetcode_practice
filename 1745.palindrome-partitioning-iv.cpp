/*
 * @lc app=leetcode id=1745 lang=cpp
 *
 * [1745] Palindrome Partitioning IV
 */

// @lc code=start
class Solution {
 public:
  bool checkPartitioning(string s) {
    int n = s.size();
    vector<bool> left(n, false), right(n, false);
    for (int i = 0; i < n; i++) {
      left[i] = isPalindrome(s, 0, i);
      right[i] = isPalindrome(s, i, n - 1);
    }

    for (int i = 0; i < n; i++) {
      for (int j = i + 2; j < n; j++) {
        if (left[i] && right[j] && isPalindrome(s, i + 1, j - 1)) return true;
      }
    }
    return false;
  }

  bool isPalindrome(string& s, int l, int r) {
    if (l > r) return false;
    for (; l < r; l++, r--) {
      if (s[l] != s[r]) return false;
    }
    return true;
  }
};
// @lc code=end
