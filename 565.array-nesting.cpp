/*
 * @lc app=leetcode id=565 lang=cpp
 *
 * [565] Array Nesting
 */

// @lc code=start
class Solution {
 public:
  // Accepted
  // 885/885 cases passed (148 ms)
  // Your runtime beats 42.2 % of cpp submissions
  // Your memory usage beats 23.51 % of cpp submissions (97.5 MB)
  // int arrayNesting(vector<int>& nums) {
  //   int res = 0;
  //   for (int i = 0; i < nums.size(); i++) {
  //     res = max(res, visit(nums, i));
  //   }
  //   return res;
  // }

  // int visit(vector<int>& nums, int i) {
  //   if (nums[i] < 0) return -nums[i];
  //   if (nums[i] == i) {
  //     nums[i] = -1;
  //     return 1;
  //   }
  //   if (nums[i] == INT_MAX) {
  //     return 0;
  //   }
  //   int next = nums[i];
  //   nums[i] = INT_MAX;
  //   nums[i] = -visit(nums, next) - 1;
  //   return -nums[i];
  // }
  int arrayNesting(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      int length = 0;
      for (int k = i; nums[k] >= 0; length++) {
        int next = nums[k];
        nums[k] = -1;
        k = next;
      }
      res = max(res, length);
    }
    return res;
  }
};
// @lc code=end
