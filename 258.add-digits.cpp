/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
 public:
  int addDigits(int num) {
    while (num > 9) {
      int v = 0;
      while (num) {
        v += num % 10;
        num /= 10;
      }
      num = v;
    }
    return num;
  }
};
// @lc code=end
