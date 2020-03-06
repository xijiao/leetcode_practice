/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int trans = 0;
        while (m < n) {
            m >>= 1;
            n >>= 1;
            trans++;
        }
        return m << trans;
    }
};
// @lc code=end

