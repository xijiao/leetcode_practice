/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }

    // bool canWinNim(int n) {
    //     if (n <= 3) return true;
    //     int p1 = true, p2 = true, p3 = true;
    //     for (int i = 4; i <= n; i++) {
    //         int p4 = !p1 || !p2 || !p3;
    //         p1 = p2; p2 = p3; p3 = p4;
    //     }
    //     return p3;
    // }
};
// @lc code=end

