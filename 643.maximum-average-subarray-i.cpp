/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int maxsum = INT_MIN, cursum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      cursum += nums[i];
      if (i >= k - 1) {
        maxsum = max(maxsum, cursum);
        cursum -= nums[i - k + 1];
      }
    }
    return (double)maxsum / k;
  }
};
// @lc code=end
