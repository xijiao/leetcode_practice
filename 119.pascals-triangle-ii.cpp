/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1, 1);
    for (int i = 2; i <= rowIndex; i++) {
      int pre = 1;
      for (int j = 1; j < i; j++) {
        int tmp = ans[j];
        ans[j] += pre;
        pre = tmp;
      }
    }
    return ans;
  }
};
// @lc code=end
