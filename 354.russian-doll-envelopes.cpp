/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int>> E;
        for (const auto& e : envelopes) {
            E.emplace_back(e[0], e[1]);
        }
        sort(E.begin(), E.end());
        int n = envelopes.size();
        vector<int> dp(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (E[i].first > E[j].first && E[i].second > E[j].second) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

