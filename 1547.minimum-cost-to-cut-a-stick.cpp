/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return find(cuts, 0, m - 1, dp);
    }

    int find(vector<int>& cuts, int l, int r, vector<vector<int>>& dp) {
        if (l + 1 == r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        int res = INT_MAX;
        int len = cuts[r] - cuts[l];
        for (int m = l + 1; m < r; m++) {
            res = min(res, find(cuts, l, m, dp) + find(cuts, m, r, dp) + len);
        }
        dp[l][r] = res;
        return res;
    }
};
// @lc code=end

