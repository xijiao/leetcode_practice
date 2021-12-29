/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

// @lc code=start
class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> count;
    for (int v : deck) count[v]++;
    int X = count.begin()->second;
    for (auto& node : count) {
      X = gcd(X, node.second);
      if (X < 2) return false;
    }
    return true;
  }

  int gcd(int a, int b) {
    while (a % b != 0) {
      int c = a % b;
      a = b;
      b = c;
    }
    return b;
  }
};
// @lc code=end
