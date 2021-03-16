/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 2, vector(n + 2, 0));
        for (int i = n; i > 0; i--) {
            for (int j = i; j <= n; j++) {
                if (i == j) dp[i][j] = 1;
                else if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[1][n];
    }

    // recursive
    // int longestPalindromeSubseq(string s) {
    //     int n = s.size();
    //     vector<vector<int>> dp(n, vector(n, -1));
    //     return find(s, 0, n - 1, dp);
    // }

    // int find(const string& s, int l, int r, vector<vector<int>>& dp) {
    //     if (l > r) return 0;
    //     if (l == r) return 1;
    //     if (dp[l][r] != -1) return dp[l][r];
    //     int res = 0;
    //     if (s[l] == s[r]) res = find(s, l + 1, r - 1, dp) + 2;
    //     else res = max(find(s, l + 1, r, dp), find(s, l, r - 1, dp));
    //     dp[l][r] = res;
    //     return res;
    // }
};
// @lc code=end

