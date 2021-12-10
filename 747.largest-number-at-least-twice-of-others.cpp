/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      if (nums.size() == 1) return 0;
      int L1 = nums[0], L2 = min(nums[0], nums[1]), L1index = 0;
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > L1) {
          L2 = L1;
          L1 = nums[i];
          L1index = i;
        } else {
          L2 = max(L2, nums[i]);
        }
      }
      return L1 >= L2 * 2 ? L1index : -1;
    }
};
// @lc code=end

