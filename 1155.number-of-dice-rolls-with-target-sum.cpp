/*
 * @lc app=leetcode id=1155 lang=cpp
 *
 * [1155] Number of Dice Rolls With Target Sum
 */

// @lc code=start
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        const int MOD = 1000000007;
        if (d * f < target) return 0;
        if (d * f == target) return 1;
        if (d == 1) return 1;
        vector<int> dp(target + 1), dppre(target + 1);
        for (int i = 1; i <= f && i <= target; i++) dp[i] = 1; // 1 round
        for (int i = 2; i <= d; i++) {
            dp.swap(dppre);
            fill(dp.begin(), dp.end(), 0);
            for (int j = i - 1; j <= target; j++) {
                if (dppre[j] == 0) break;
                for (int k = 1; k <= f; k++) {
                    if (j + k > target) break;
                    dp[j + k] = (dp[j + k] + dppre[j]) % MOD;
                }
            }
        }
        // for (int d : dp) cout << d << " ";
        // cout << endl;
        return dp[target];
    }
};
// @lc code=end

