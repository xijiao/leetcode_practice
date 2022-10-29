/*
 * @lc app=leetcode id=1566 lang=cpp
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */

// @lc code=start
class Solution {
 public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    for (int offset = 0; offset < m; offset++) {
      int repeat = 1;
      for (int i = offset + m; i + m <= arr.size(); i += m) {
        bool equal = true;
        for (int j = i - m; j < i; j++) {
          if (arr[j] != arr[j + m]) {
            equal = false;
            break;
          }
        }
        if (equal) {
          if (++repeat >= k) return true;
        } else {
          repeat = 1;
        }
      }
    }
    return false;
  }
};
// @lc code=end
