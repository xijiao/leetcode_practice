/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

// @lc code=start
class Solution {
 public:
  bool checkPerfectNumber(int num) {
    int sum = 0;
    for (int i = num / 2; i > 0; --i) {
      if (num % i == 0) sum += i;
    }
    return sum == num;
  }
};
// @lc code=end
