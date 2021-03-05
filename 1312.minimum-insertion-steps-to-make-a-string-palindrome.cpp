/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minInsertionsDP(s, 0, n - 1, dp);
    }

    int minInsertionsDP(const string& s, int l, int r, vector<vector<int>>& dp) {
        if (l >= r) return 0;
        if (dp[l][r] >= 0) return dp[l][r];
        int res = 0;
        if (s[l] == s[r]) {
            res = minInsertionsDP(s, l + 1, r - 1, dp);
        } else {
            res = min(minInsertionsDP(s, l + 1, r, dp), minInsertionsDP(s, l, r - 1, dp)) + 1;
        }
        dp[l][r] = res;
        return res;
    }
};
// @lc code=end

