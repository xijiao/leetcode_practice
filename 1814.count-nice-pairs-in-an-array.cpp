/*
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
      const int MOD = 1e9 + 7;
      unordered_map<int, int> count;
      int ans = 0;
      for (int num : nums) {
        ans = (ans + count[num - rev(num)]++) % MOD;
      }
      return ans;
    }

    int rev(int num) {
      int res = 0;
      while (num) {
        res = res * 10 + num % 10;
        num /= 10;
      }
      return res;
    }
};
// @lc code=end

