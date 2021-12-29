/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

// @lc code=start
class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    reverse(num.begin(), num.end());
    for (int index = 0, adv = 0; k || adv; ++index) {
      if (index >= num.size()) num.push_back(0);
      num[index] += (adv + k % 10);
      adv = num[index] / 10;
      num[index] %= 10;
      k /= 10;
    }
    reverse(num.begin(), num.end());
    return num;
  }
};
// @lc code=end
