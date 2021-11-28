/*
 * @lc app=leetcode id=1497 lang=cpp
 *
 * [1497] Check If Array Pairs Are Divisible by k
 */

// @lc code=start
class Solution {
 public:
  bool canArrange(vector<int>& arr, int k) {
    if (k <= 0) return false;
    if (k == 1) return true;
    unordered_map<int, int> count;
    for (int v : arr) {
      count[(v % k + k) % k]++;
    }
    for (int i = k / 2; i >= 0; --i) {
      if (i == 0 || k - i == i) {
        if (count[i] % 2 != 0) return false;
      } else {
        if (count[i] != count[k - i]) return false;
      }
    }
    return true;
  }
};
// @lc code=end
