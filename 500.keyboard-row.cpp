/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

// @lc code=start
class Solution {
 public:
  vector<string> findWords(vector<string>& words) {
    vector<int> row(26);
    for (char c : "qwertyuiop") {
      if (c == 0) break;
      row[c - 'a'] = 1;
    }
    for (char c : "asdfghjkl") {
      if (c == 0) break;
      row[c - 'a'] = 2;
    }
    for (char c : "zxcvbnm") {
      if (c == 0) break;
      row[c - 'a'] = 3;
    }
    vector<string> ans;
    for (string& word : words) {
      int rowid = 0;
      bool unmatch = false;
      for (char c : word) {
        c = tolower(c);
        if (rowid == 0)
          rowid = row[c - 'a'];
        else if (rowid != row[c - 'a']) {
          unmatch = true;
          break;
        }
      }
      if (!unmatch) {
        ans.push_back(word);
      }
    }
    return ans;
  }
};
// @lc code=end
