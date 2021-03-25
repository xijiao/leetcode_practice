/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;
        int adv = 0;
        for (int i = 0; i < 32; i++) {
            adv <<= 1;
            int bita = a & (1 << i);
            int bitb = b & (1 << i);
            res |= (bita ^ bitb ^ adv);
            adv = (bita & bitb) | (bita & adv) | (bitb & adv);
        }
        return res;
    }
};
// @lc code=end

