/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

// @lc code=start
class Solution {
 public:
  bool checkRecord(string s) {
    int absents = 0, lateconsecutives = 0;
    for (char c : s) {
      if (c == 'A') {
        if (++absents >= 2) return false;
      }
      if (c == 'L') {
        if (++lateconsecutives >= 3) return false;
      } else {
        lateconsecutives = 0;
      }
    }
    return true;
  }
};
// @lc code=end
