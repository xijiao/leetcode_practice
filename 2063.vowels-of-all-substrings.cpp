/*
 * @lc app=leetcode id=2063 lang=cpp
 *
 * [2063] Vowels of All Substrings
 */

// @lc code=start
class Solution {
 public:
  long long countVowels(string word) {
    unordered_set<int> Vowels{'a', 'e', 'i', 'o', 'u'};
    long long res = 0, count = 0;
    int n = word.size();
    for (int i = 0; i < n; ++i) {
      char c = word[i];
      if (Vowels.count(c)) {
        count += (i + 1);
      }
      res += count;
    }
    return res;
  }
};
// @lc code=end
