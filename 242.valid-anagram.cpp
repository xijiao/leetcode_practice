/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<int, int> count1, count2;
    for (char c : s) count1[c]++;
    for (char c : t) count2[c]++;
    return count1 == count2;
  }
};
// @lc code=end
