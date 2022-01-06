/*
 * @lc app=leetcode id=2064 lang=cpp
 *
 * [2064] Minimized Maximum of Products Distributed to Any Store
 */

// @lc code=start
class Solution {
 public:
  int minimizedMaximum(int n, vector<int>& quantities) {
    int maxQ = 0;
    for (int q : quantities) maxQ = max(maxQ, q);
    int l = 1, r = maxQ;
    for (; l < r;) {
      int m = (l + r) / 2;
      if (isPossibleX(n, quantities, m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }

  bool isPossibleX(int n, vector<int>& quantities, int x) {
    int needStores = 0;
    for (int q : quantities) {
      needStores += (q + x - 1) / x;
      if (needStores > n) return false;
    }
    return true;
  }
};
// @lc code=end
