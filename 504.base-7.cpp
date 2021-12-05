/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

// @lc code=start
class Solution {
 public:
  string convertToBase7(int num) {
    bool negative = num < 0;
    num = abs(num);
    string ans;
    for (; num; num /= 7) {
      ans.push_back('0' + num % 7);
    }
    if (ans.empty()) ans.push_back('0');
    if (negative) ans.push_back('-');
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
