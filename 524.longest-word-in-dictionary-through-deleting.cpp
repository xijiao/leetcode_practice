/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 */

// @lc code=start
class Solution {
 public:
  string findLongestWord(string s, vector<string>& dictionary) {
    int n = dictionary.size();
    vector<int> index(n);
    unordered_map<int, vector<int>> M;
    for (int i = 0; i < n; ++i) {
      M[dictionary[i][0]].push_back(i);
    }
    for (char c : s) {
      vector<int> curset;
      curset.swap(M[c]);
      for (int i : curset) {
        if (++index[i] >= dictionary[i].size()) continue;
        M[dictionary[i][index[i]]].push_back(i);
      }
    }
    int maxlen = 0;
    int maxindex = -1;
    for (int i = 0; i < n; ++i) {
      if (index[i] == dictionary[i].size() &&
          (index[i] > maxlen ||
           (index[i] == maxlen && dictionary[i] < dictionary[maxindex]))) {
        maxlen = index[i];
        maxindex = i;
      }
    }
    return maxindex == -1 ? "" : dictionary[maxindex];
  }
};
// @lc code=end
