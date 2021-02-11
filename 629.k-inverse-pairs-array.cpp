/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// dp(n, 0) = 1;
// dp(n, k) = 0; for k > n(n-1)/2
// dp(n, k) = dp(n - 1, k) + dp(n - 1, k - 1) + dp(n - 1, k - 2)... + dp(n - 1, k - n + 1)
// dp(n, k - 1) = dp(n - 1, k - 1) + dp(n - 1, k - 2)... dp(n - 1, k - n)
// dp(n, k) = dp(n - 1, k) + dp(n, k - 1) - dp(n - 1, k - n);

// @lc code=start
class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1000000007;
        vector<int> dp(k + 1, 0);
        vector<int> dp2(k + 1, 0);
        dp[0] = dp2[0] = 1; // n = 1: 1, 0, 0, 0
        for (int i = 2; i <= n; i++) {
            dp.swap(dp2);
            dp[0] = 1;
            for (int j = 1; j <= k && j <= (i * (i - 1) / 2); j++) {
                dp[j] = dp2[j] + dp[j - 1];
                dp[j] = dp[j] % MOD;
                if (j - i >= 0) dp[j] -= dp2[j - i];
                dp[j] = (dp[j] + MOD) % MOD;
            }
        }
        // n = 2: 1, 1, 0, 0
        // n = 3: 1, 2, 2, 1

        return dp[k]; // 2
    }
};
// @lc code=end

