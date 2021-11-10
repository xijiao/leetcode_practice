/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

// @lc code=start
class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    int degree = 0;
    unordered_map<int, int> count, first, last;

    for (int i = 0; i < nums.size(); i++) {
      int num = nums[i];
      degree = max(degree, ++count[num]);
      if (!first.count(num)) first[num] = i;
      last[num] = i;
    }

    int res = nums.size();
    for (auto& node : count) {
      if (node.second == degree) {
        res = min(res, last[node.first] - first[node.first] + 1);
      }
    }
    return res;
  }
};
// @lc code=end
