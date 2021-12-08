/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

// @lc code=start
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> M;
    for (int n : nums) M[n]++;
    vector<int> ans(2);
    for (int i = 1; i <= n; ++i) {
      if (M[i] == 2)
        ans[0] = i;
      else if (M[i] == 0)
        ans[1] = i;
    }
    return ans;
  }
};
// @lc code=end
