/*
 * @lc app=leetcode id=961 lang=cpp
 *
 * [961] N-Repeated Element in Size 2N Array
 */

// @lc code=start
class Solution {
 public:
  int repeatedNTimes(vector<int>& nums) {
    unordered_map<int, int> count;
    for (int n : nums) {
      if (count[n]++ == 1) return n;
    }
    return -1;
  }
};
// @lc code=end
