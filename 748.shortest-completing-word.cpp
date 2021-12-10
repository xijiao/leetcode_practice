/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

// @lc code=start
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
      unordered_map<int, int> M;
      countCharacter(licensePlate, M);
      int index = -1;
      for (int i = 0; i < words.size(); ++i) {
        unordered_map<int, int> m;
        countCharacter(words[i], m);
        bool completing = true;
        for (auto& node : M) {
          if (m[node.first] < node.second) {
            completing = false;
            break;
          }
        }
        if (completing && (index == -1 || words[i].size() < words[index].size())) {
          index = i;
        }
      }
      return words[index];
    }

    void countCharacter(const string& s, unordered_map<int, int>& M) {
      for (char c : s) {
        if (isalpha(c)) {
          M[tolower(c)]++;
        }
      }
    }
};
// @lc code=end

