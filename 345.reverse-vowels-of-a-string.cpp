/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
 public:
  string reverseVowels(string s) {
    unordered_set<int> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int l = 0, r = s.size(); l < r;) {
      if (!vowels.count(s[l]))
        ++l;
      else if (!vowels.count(s[r]))
        --r;
      else {
        swap(s[l++], s[r--]);
      }
    }
    return s;
  }
};
// @lc code=end
