/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

// @lc code=start
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0;
        for (;n && n >= (1 + i); i++) {
            n -= (1 + i);
        }
        return i;
    }
};
// @lc code=end

