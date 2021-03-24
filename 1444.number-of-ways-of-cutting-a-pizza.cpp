/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        const int MOD = 1000000007;
        int m = pizza.size();
        int n = pizza[0].size();
        vector<vector<int>> count(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                count[i][j] = count[i + 1][j] + count[i][j + 1] - count[i + 1][j + 1];
                if (pizza[i][j] == 'A') count[i][j]++;
            }
        }
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (count[i][j] > 0) dp[0][i][j] = 1;
            }
        }
        for (int t = 1; t < k; t++) {
            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    for (int p = i + 1; p < m; p++) {
                        if (count[i][j] == count[p][j]) continue;
                        dp[t][i][j] += dp[t - 1][p][j];
                        dp[t][i][j] %= MOD;
                    }
                    for (int p = j + 1; p < n; p++) {
                        if (count[i][j] == count[i][p]) continue;
                        dp[t][i][j] += dp[t - 1][i][p];
                        dp[t][i][j] %= MOD;
                    }
                }
            }
        }
        // for (int t = 0; t < k; t++) {
        //     for (int i = 0; i <= m; i++) {
        //         for (int j = 0; j <= n; j++) {
        //             cout << dp[t][i][j] << " ";
        //         }
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        return dp[k - 1][0][0];
    }
};
// @lc code=end

