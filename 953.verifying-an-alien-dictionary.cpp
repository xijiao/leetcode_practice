/*
 * @lc app=leetcode id=953 lang=cpp
 *
 * [953] Verifying an Alien Dictionary
 */

// @lc code=start
class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    string smap;
    smap.resize(26);
    for (int i = 0; i < 26; i++) {
      smap[order[i] - 'a'] = 'a' + i;
    }
    for (string& word : words) {
      for (char& c : word) {
        c = smap[c - 'a'];
      }
    }
    for (int i = 0; i < words.size() - 1; i++) {
      if (words[i] > words[i + 1]) return false;
    }
    return true;
  }
};
// @lc code=end
