/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

// @lc code=start
class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    unordered_map<int, int> trustcount, betrustedcount;
    for (auto& t : trust) {
      trustcount[t[0]]++;
      betrustedcount[t[1]]++;
    }
    for (int i = 1; i <= n; ++i) {
      if (trustcount[i] == 0 && betrustedcount[i] == n - 1) return i;
    }
    return -1;
  }
};
// @lc code=end
