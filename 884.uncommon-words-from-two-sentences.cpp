/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

// @lc code=start
class Solution {
 public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> count;
    doCount(s1, count);
    doCount(s2, count);
    vector<string> ans;
    for (auto& node : count) {
      if (node.second == 1) {
        ans.push_back(node.first);
      }
    }
    return ans;
  }

  void doCount(string& s, unordered_map<string, int>& count) {
    for (int start = 0, pos = s.find(' ');; pos = s.find(' ', start)) {
      if (pos == string::npos) {
        count[s.substr(start, s.size() - start)]++;
        break;
      } else {
        count[s.substr(start, pos - start)]++;
        start = pos + 1;
      }
    }
  }
};
// @lc code=end
