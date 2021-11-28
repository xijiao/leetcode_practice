/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    unordered_set<int> found;
    found.insert(n);
    while (true) {
      int m = 0;
      while (n) {
        int c = n % 10;
        m += c * c;
        n /= 10;
      }
      if (m == 1) return true;
      if (found.count(m)) return false;
      n = m;
      found.insert(m);
    }
    return false;
  }
};
// @lc code=end
