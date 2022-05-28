/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 */

// @lc code=start
class Solution {
 public:
  int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0) return -1;
    int res = 0, v = 0;
    for (;;) {
      for (; v <= 0 || v % 10 != 1; v += k)
        ;
      res++;
      v = v / 10;
      if (v == 0) break;
    }
    return res;
  }
};
// @lc code=end
