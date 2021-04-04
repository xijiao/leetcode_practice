/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int BASE = 1000;
        if (S > 1000 || S < -1000) return 0;
        vector<int> dp(2001), dp1(2001);
        dp[BASE + 0] = 1;
        for (int num : nums) {
            fill(dp1.begin(), dp1.end(), 0);
            for (int i = -BASE; i <= BASE; i++) {
                //cout << num << " " << i << " " << dp[i + BASE] << " " << endl;
                if (dp[i + BASE] == 0) continue;
                dp1[i + num + BASE] += dp[i + BASE];
                dp1[i - num + BASE] += dp[i + BASE];
            }
            dp.swap(dp1);
        }
        return dp[S + BASE];
    }
};
// @lc code=end

