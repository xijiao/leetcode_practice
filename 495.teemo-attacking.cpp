/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start
class Solution {
 public:
  int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int endtime = -1, ans = 0;
    for (int time : timeSeries) {
      if (endtime < time) {
        ans += duration;
      } else {
        ans += (time + duration - 1 - endtime);
      }
      endtime = time + duration - 1;
    }
    return ans;
  }
};
// @lc code=end
