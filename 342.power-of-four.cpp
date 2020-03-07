/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num < 1) return false;
        if (num & (num - 1)) return false;
        int dis = 0;
        while (num != 1) {
            dis ++;
            num >>= 1;
        }
        return dis % 2 == 0;
    }
};
// @lc code=end

