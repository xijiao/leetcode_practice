/*
 * @lc app=leetcode id=1094 lang=cpp
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> pickdrop(1001);
    for (vector<int>& trip : trips) {
      pickdrop[trip[1]] += trip[0];
      pickdrop[trip[2]] -= trip[0];
    }
    int passengers = 0;
    for (int i = 0; i <= 1000; ++i) {
      passengers += pickdrop[i];
      if (passengers > capacity) return false;
    }
    return true;
  }
};
// @lc code=end
