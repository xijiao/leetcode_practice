/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
 public:
  // Recursive
  //   int findMin(vector<int>& nums) {
  //     return binarySearch(nums, 0, nums.size() - 1);
  //   }

  //   int binarySearch(vector<int>& nums, int l, int r) {
  //     if (l == r) return nums[l];
  //     if (l + 1 == r) return min(nums[l], nums[r]);
  //     int m = (l + r) / 2;
  //     if (nums[l] > nums[m])
  //       return binarySearch(nums, l, m);
  //     else if (nums[m] > nums[r])
  //       return binarySearch(nums, m + 1, r);
  //     else if (nums[l] < nums[r])
  //       return nums[l];
  //     else
  //       return binarySearch(nums, l, r - 1);
  //   }

  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (nums[l] > nums[m])
        r = m;
      else if (nums[m] > nums[r])
        l = m + 1;
      else if (nums[l] < nums[r])
        r = l;
      else
        r--;
    }
    return nums[l];
  }
};
// @lc code=end
