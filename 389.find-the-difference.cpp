/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
 public:
  char findTheDifference(string s, string t) {
    unordered_map<int, int> countS, countT;
    doCounting(s, countS);
    doCounting(t, countT);
    for (auto& node : countT) {
      if (node.second > countS[node.first]) return node.first;
    }
    return 0;
  }

  void doCounting(string& s, unordered_map<int, int>& count) {
    for (char c : s) count[c]++;
  }
};
// @lc code=end
