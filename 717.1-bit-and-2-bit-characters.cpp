/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    for (int i = 0; i < bits.size();) {
      if (i == bits.size() - 1) return true;
      if (bits[i] == 1)
        i += 2;
      else
        i++;
    }
    return false;
  }
};
// @lc code=end
