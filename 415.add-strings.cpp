/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
 public:
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ans;
    int pre = 0;
    for (int i = 0; i < num1.size() || i < num2.size(); ++i) {
      int cur = pre;
      if (i < num1.size()) cur += (num1[i] - '0');
      if (i < num2.size()) cur += (num2[i] - '0');
      ans.push_back('0' + (cur % 10));
      pre = cur / 10;
    }
    if (pre) {
      ans.push_back('0' + pre);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
