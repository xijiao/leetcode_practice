/*
 * @lc app=leetcode id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

// @lc code=start
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int rod : rods) {
            unordered_map<int, int> cur(dp);
            for (const auto& p : cur) {
                int d = p.first;
                dp[d + rod] = max(dp[d + rod], p.second);
                dp[abs(d - rod)] = max(dp[abs(d - rod)], min(d, rod) + p.second);
            }
        }
        return dp[0];
    }
};
// @lc code=end

