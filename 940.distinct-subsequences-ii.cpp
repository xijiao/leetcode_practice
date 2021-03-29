/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 */

// @lc code=start
class Solution {
public:
    int distinctSubseqII(string S) {
        const int MOD = 1000000007;
        int res = 0;
        vector<int> dp(S.size(), 1);
        for (int i = 0; i < S.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (S[i] == S[j]) continue;
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
            res += dp[i];
            res %= MOD;
        }
        return res;
    }
};
// @lc code=end

