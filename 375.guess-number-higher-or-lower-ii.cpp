/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return find(dp, 1, n);
    }

    int find(vector<vector<int>>& dp, int l, int r) {
        if (dp[l][r] != -1) return dp[l][r];
        if (l == r) return 0;
        if (l + 1 == r) return l;
        int res = INT_MAX;
        for (int i = l + 1; i < r; i++) {
            res = min(res, i + max(find(dp, l, i - 1), find(dp, i + 1, r)));
        }
        dp[l][r] = res;
        return res;
    }
};
// @lc code=end

