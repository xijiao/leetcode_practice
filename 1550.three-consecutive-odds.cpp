/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

// @lc code=start
class Solution {
 public:
  bool threeConsecutiveOdds(vector<int>& arr) {
    int consecutives = 0;
    for (int v : arr) {
      if (v % 2) {
        if (++consecutives == 3) return true;
      } else {
        consecutives = 0;
      }
    }
    return false;
  }
};
// @lc code=end
