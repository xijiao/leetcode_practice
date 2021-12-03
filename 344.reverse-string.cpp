/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
 public:
  void reverseString(vector<char>& s) {
    if (s.size() == 0) return;
    for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
      swap(s[l], s[r]);
    }
  }
};
// @lc code=end
