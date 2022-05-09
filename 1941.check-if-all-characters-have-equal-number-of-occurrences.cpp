/*
 * @lc app=leetcode id=1941 lang=cpp
 *
 * [1941] Check if All Characters Have Equal Number of Occurrences
 */

// @lc code=start
class Solution {
 public:
  bool areOccurrencesEqual(string s) {
    unordered_map<int, int> count;
    for (char c : s) {
      count[c]++;
    }
    int occur = 0;
    for (const auto& pair : count) {
      if (occur == 0) {
        occur = pair.second;
      } else if (occur != pair.second) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
