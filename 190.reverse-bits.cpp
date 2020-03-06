/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t t1 = n << 16 | n >> 16;
        uint32_t t2 = (t1 << 8 & 0xFF00FF00) | (t1 >> 8 & 0x00FF00FF);
        uint32_t t3 = (t2 << 4 & 0xF0F0F0F0) | (t2 >> 4 & 0x0F0F0F0F);
        uint32_t t4 = (t3 << 2 & 0xCCCCCCCC) | (t3 >> 2 & 0x33333333);
        uint32_t t5 = (t4 << 1 & 0xAAAAAAAA) | (t4 >> 1 & 0x55555555);
        return t5;
    }
};
// @lc code=end

