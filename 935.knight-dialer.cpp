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
        vector<int> dp(10, 1);
        for (int i = 1; i < N; i++) {
            vector<int> dp2(10, 0);
            for (int j = 0; j < 10; j++) {
                for (int k : DIRS[j]) {
                    dp2[k] += dp[j];
                    dp2[k] %= MOD;
                }
            }
            dp.swap(dp2);
        }
        int res = 0;
        for (int v : dp) {
            res += v;
            res %= MOD;
        }
        return res;
    }
};
// @lc code=end

