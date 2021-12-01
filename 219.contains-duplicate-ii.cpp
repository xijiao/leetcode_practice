/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> M;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (M.count(nums[i]) && i - M[nums[i]] <= k) {
        return true;
      }
      M[nums[i]] = i;
    }
    return false;
  }
};
// @lc code=end
