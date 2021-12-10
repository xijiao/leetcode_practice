/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        while (l < r) {
          int m = (l + r) / 2;
          if (letters[m] > target) {
            r = m;
          } else {
            l = m + 1;
          }
        }
        return letters[l] > target ? letters[l] : letters[0];
    }
};
// @lc code=end

