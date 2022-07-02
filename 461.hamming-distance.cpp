/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

// @lc code=start
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int ans = 0;
    for (int v = x ^ y; v; v &= (v - 1), ans++)
      ;
    return ans;
  }
};
// @lc code=end
