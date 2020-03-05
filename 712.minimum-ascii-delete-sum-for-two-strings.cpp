/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int dp[s1.size() + 1];
        dp[0] = 0;
        for (int i = 0; i < s1.size(); i++) dp[i + 1] = dp[i] + s1[i];
        for (int i = 1; i < s2.size() + 1; i++) {
            int t = dp[0];
            dp[0] += s2[i - 1];
            for (int j = 1; j < s1.size() + 1; j++) {
                int p = dp[j];
                if (s1[j - 1] == s2[i - 1]) dp[j] = t;
                else dp[j] = min(dp[j - 1] + s1[j - 1], dp[j] + s2[i - 1]);
                t = p;
            }
        }
        return dp[s1.size()];
    }
};
// @lc code=end

