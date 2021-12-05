/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
 public:
  int fib(int n) {
    if (n <= 1) return n;
    int v1 = 0, v2 = 1;
    for (int i = 2; i <= n; i++) {
      int v3 = v1 + v2;
      v1 = v2;
      v2 = v3;
    }
    return v2;
  }
};
// @lc code=end
