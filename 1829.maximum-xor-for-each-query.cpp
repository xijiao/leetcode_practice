/*
 * @lc app=leetcode id=1829 lang=cpp
 *
 * [1829] Maximum XOR for Each Query
 */

// @lc code=start
class Solution {
public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    int n = nums.size(), v = 0;
    vector<int> ans(n);
    int mask = (1 << maximumBit) - 1;
    for (int i = 0; i < n; i++) {
      v ^= nums[i];
      ans[n - i - 1] = mask ^ v;
    }
    return ans;
  }
};
// @lc code=end

