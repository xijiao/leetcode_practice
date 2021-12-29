/*
 * @lc app=leetcode id=896 lang=cpp
 *
 * [896] Monotonic Array
 */

// @lc code=start
class Solution {
  enum {
    INC,
    DEC,
    INITIAL,
  };

 public:
  bool isMonotonic(vector<int>& nums) {
    int status = INITIAL;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > nums[i - 1]) {
        if (status == DEC) return false;
        status = INC;
      } else if (nums[i] < nums[i - 1]) {
        if (status == INC) return false;
        status = DEC;
      }
    }
    return true;
  }
};
// @lc code=end
