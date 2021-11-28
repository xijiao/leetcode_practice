/*
 * @lc app=leetcode id=1202 lang=cpp
 *
 * [1202] Smallest String With Swaps
 */

// @lc code=start
class Solution {
  unordered_map<int, int> U;
  int find(int x) {
    if (!U.count(x)) {
      U[x] = x;
    }
    if (U[x] != x) {
      U[x] = find(U[x]);
    }
    return U[x];
  }

  void uni(int x, int y) {
    x = find(x);
    y = find(y);
    U[x] = U[y];
  }

 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    for (vector<int>& pair : pairs) {
      uni(pair[0], pair[1]);
    }
    unordered_map<int, string> M;
    for (int i = 0; i < n; ++i) {
      M[find(i)].push_back(s[i]);
    }
    for (auto& node : M) {
      sort(node.second.begin(), node.second.end());
    }
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
      s[i] = M[find(i)][index[find(i)]++];
    }
    return s;
  }
};
// @lc code=end
