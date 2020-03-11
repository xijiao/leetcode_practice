/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
public:
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(G + 1, vector<int>(P + 1, 0));
        dp[0][0] = 1;
        int n = group.size();
        int M = 1000000007;
        for (int k = 0; k < n; k++) {
            int g = group[k];
            int p = profit[k];
            for (int i = G - g; i >= 0; i--) {
                int ii = i + g;
                for (int j = P; j >= 0; j--) {
                    int jj = min(j + p, P);
                    dp[ii][jj] += dp[i][j];
                    dp[ii][jj] %= M;
                }
            }
        }
        int res = 0;
        for (int i = 0; i <= G; i++) {
            res += dp[i][P];
            res %= M;
        }
        return res;;
    }
};
// @lc code=end

