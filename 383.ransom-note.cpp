/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> count(26);
    for (char c : magazine) {
      count[c - 'a']++;
    }
    for (char c : ransomNote) {
      if (--count[c - 'a'] < 0) return false;
    }
    return true;
  }
};
// @lc code=end
