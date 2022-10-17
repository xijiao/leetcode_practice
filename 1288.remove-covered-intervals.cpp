/*
 * @lc app=leetcode id=1288 lang=cpp
 *
 * [1288] Remove Covered Intervals
 */

// @lc code=start
class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& l, const vector<int>& r) {
           if (l[0] != r[0])
             return l[0] < r[0];
           else
             return l[1] > r[1];
         });
    int ans = 0;
    int curRight = -1;
    for (vector<int>& inv : intervals) {
      if (curRight >= inv[1]) continue;
      curRight = max(curRight, inv[1]);
      ans++;
    }
    return ans;
  }
};
// @lc code=end
