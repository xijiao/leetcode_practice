/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

// @lc code=start
class Solution {
 public:
  int specialArray(vector<int>& nums) {
    int maxV = 0;
    for (int n : nums) maxV = max(maxV, n);
    vector<int> count(maxV + 1, 0);
    for (int n : nums) count[n]++;
    int total = 0;
    for (int v = maxV; v >= 0; v--) {
      total += count[v];
      if (total == v) return v;
    }
    return -1;
  }
};
// @lc code=end
