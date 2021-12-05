/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

// @lc code=start
class Solution {
 public:
  bool detectCapitalUse(string word) {
    if (word.size() <= 1) return true;
    bool firstCapital = isupper(word[0]), secondCapital = isupper(word[1]);
    if (!firstCapital && secondCapital) return false;
    for (int i = 2; i < word.size(); ++i) {
      if ((bool)isupper(word[i]) != secondCapital) return false;
    }
    return true;
  }
};
// @lc code=end
