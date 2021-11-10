/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    int count[26] = {};
    for (int i = 0; i < 26; i++) count[i] = 100;
    for (string& word : words) {
      int count2[26] = {0};
      for (char c : word) {
        count2[c - 'a']++;
      }
      for (int i = 0; i < 26; i++) count[i] = min(count[i], count2[i]);
    }
    vector<string> res;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < count[i]; j++) {
        string s(" ", 1);
        s[0] = 'a' + i;
        res.push_back(s);
      }
    }
    return res;
  }
};
// @lc code=end
