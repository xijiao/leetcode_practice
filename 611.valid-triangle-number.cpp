/*
 * @lc app=leetcode id=611 lang=cpp
 *
 * [611] Valid Triangle Number
 */

// @lc code=start
class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
      for (int l = 0, r = i - 1; l < r;) {
        if (nums[l] + nums[r] > nums[i]) {
          ans += (r - l);
          --r;
        } else {
          ++l;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
