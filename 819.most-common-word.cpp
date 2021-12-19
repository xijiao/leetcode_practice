/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

// @lc code=start
class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> B(banned.begin(), banned.end());
    unordered_map<string, int> count;
    for (int l = 0, r = 0; r <= paragraph.size(); r++) {
      if (r == paragraph.size() || !isalpha(paragraph[r])) {
        if (r > l) {
          string word = paragraph.substr(l, r - l);
          toLower(word);
          if (!B.count(word)) {
            count[word]++;
          }
        }
        l = r + 1;
      }
    }
    int maxcount = 0;
    const string* res = nullptr;
    for (auto& node : count) {
      if (node.second > maxcount) {
        maxcount = node.second;
        res = &(node.first);
      }
    }
    return *res;
  }

  void toLower(string& s) {
    for (char& c : s) c = tolower(c);
  }
};
// @lc code=end
