/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start
class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int nameindex = 0, lastchar = -1;
    for (char c : typed) {
      if (nameindex < name.size() && name[nameindex] == c) {
        nameindex++;
      } else if (lastchar != c) {
        return false;
      }
      lastchar = c;
    }
    return nameindex == name.size();
  }
};
// @lc code=end
