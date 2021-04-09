/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

// @lc code=start
class Solution {
public:
    int findComplement(int num) {
        int leftbit = 0;
        for (leftbit = 30; leftbit >= 0; leftbit--) {
            if (num & (1 << leftbit)) break;
        }

        return num ^ ((1U << (leftbit + 1)) - 1);
    }
};
// @lc code=end

