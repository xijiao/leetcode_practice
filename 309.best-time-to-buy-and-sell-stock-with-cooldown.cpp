/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<vector<int>> dp(2, vector<int>(n, 0)); // 0->no stock, 1->has stock
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        dp[0][1] = max(dp[0][0], prices[1] + dp[1][0]);
        dp[1][1] = max(dp[1][0], dp[0][0] - prices[1]);
        for (int i = 2; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 2] - prices[i]);
        }
        return dp[0][n - 1];
    }
};
// @lc code=end

