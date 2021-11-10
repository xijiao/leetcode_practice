/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int pre = 0;
    string res;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
      int v1 = i < a.size() ? a[i] - '0' : 0;
      int v2 = i < b.size() ? b[i] - '0' : 0;
      pre += (v1 + v2);
      res.push_back('0' + (pre % 2));
      pre /= 2;
    }
    if (pre != 0) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
