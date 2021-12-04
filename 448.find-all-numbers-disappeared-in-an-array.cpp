/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    int n = nums.size(), count = 0;
    vector<int> ans(n, 0);
    for (int n : nums) ans[n - 1]++;
    for (int i = 1; i <= n; i++) {
      if (ans[i - 1] == 0) {
        ans[count++] = i;
      }
    }
    ans.resize(count);
    return ans;
  }
};
// @lc code=end
