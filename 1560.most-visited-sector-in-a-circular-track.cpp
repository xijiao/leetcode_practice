/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

// @lc code=start
class Solution {
 public:
  vector<int> mostVisited(int n, vector<int>& rounds) {
    int first = rounds[0], last = rounds[rounds.size() - 1];

    vector<int> res;
    if (first <= last) {
      res.reserve(last - first + 1);
      for (int i = first; i <= last; i++) {
        res.push_back(i);
      }
    } else {
      res.reserve(last + n - first + 1);
      for (int i = 1; i <= last; i++) {
        res.push_back(i);
      }
      for (int i = first; i <= n; i++) {
        res.push_back(i);
      }
    }
    return res;
  }
};
// @lc code=end
