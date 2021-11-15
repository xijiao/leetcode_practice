/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
 public:
  // Time Limit Exceeded
  // 52/54 cases passed (N/A)
  // bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
  //   int n = nums.size();
  //   for (int i = 0; i < n; i++) {
  //     for (int j = i + 1; j < n && j <= i + k; j++) {
  //       if (abs((long)nums[i] - nums[j]) <= t) return true;
  //     }
  //   }
  //   return false;
  // }

  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if (k == 0) return false;
    multiset<int> S;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i > k) {
        S.erase(nums[i - k - 1]);
      }
      auto it = S.upper_bound(nums[i]);
      if (it != S.end() && abs((long)nums[i] - *it) <= t) return true;
      if (it != S.begin() && abs((long)nums[i] - *(--it)) <= t) return true;
      S.insert(nums[i]);
    }
    return false;
  }
};
// @lc code=end
