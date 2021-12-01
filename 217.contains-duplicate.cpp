/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> M;
    for (int n : nums) {
      if (M.count(n)) return true;
      M.insert(n);
    }
    return false;
  }
};
// @lc code=end
