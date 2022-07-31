/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

// @lc code=start
class Solution {
 public:
  bool checkIfPangram(string sentence) {
    unordered_set<char> S;
    S.insert(sentence.begin(), sentence.end());
    return S.size() == 26;
  }
};
// @lc code=end
