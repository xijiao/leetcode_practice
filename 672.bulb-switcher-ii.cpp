/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
class Solution {
public:
    int flipLights(int n, int presses) {
        if (n == 0 || presses == 0) return 1; // no op
        if (n == 1) return 2; // [on], [off]
        if (n == 2 && presses == 1) return 3; // op1, op2, op3 = op4
        if (n == 2 && presses >= 2) return 4; // all_on, op1, op2, op3 = op4
        if (n >= 3 && presses == 1) return 4; // op1, op2, op3, op4
        if (n >= 3 && presses == 2) return 7; // all_on, op1, op2, op3, op1 + op4, op2 + op4, op3 + op4
        return 8; // (n >= 3, presses >= 3) all_on, op1, op2, op3, op4, op1 + op4, op2 + op4, op3 + op4
    }
};
// @lc code=end

