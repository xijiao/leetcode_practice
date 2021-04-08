/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[1] = true;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

// 0 false
// 1 true
// 2 false
// 3 true
// 4 true
// 5 false
// 6 true
// 7 false
// 8 true
// 9 true
// 10 false
// 11 true
// 12 false
// 13 