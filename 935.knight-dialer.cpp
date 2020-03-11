/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
 */

// @lc code=start
class Solution {
public:
    const int MOD = 1000000007;
    int knightDialer(int N) {
        vector<vector<int>> DIRS = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9},
                {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
        vector<vector<int>> dp(2, vector(10, 1));
        for (int i = 2; i <= N; i++) {
            for (int& v : dp[(i - 1) % 2]) v = 0;
            for (int j = 0; j < 10; j++) {
                for (int k : DIRS[j]) {
                    dp[(i - 1) % 2][k] += dp[i % 2][j];
                    dp[(i - 1) % 2][k] %= MOD;
                }
            }
        }
        int res = 0;
        for (int v : dp[(N - 1) % 2]) {
            res += v;
            res %= MOD;
        }
        return res;
    }
};
// @lc code=end

