/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    vector<int> count(101);
    int ans = 0;
    for (int n : nums) {
      int c = ++count[n];
      if (c == 1) {
        ans += n;
      } else if (c == 2) {
        ans -= n;
      }
    }
    return ans;
  }
};
// @lc code=end
