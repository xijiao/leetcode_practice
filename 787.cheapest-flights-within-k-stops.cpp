/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int res = -1;
        vector<int> dp(n, -1), dppre(n, -1);
        dppre[src] = 0;
        for (; K >= 0; K--) {
            for (const auto& flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];
                if (dppre[from] == -1) continue;
                if (dp[to] == -1 || dp[to] > dppre[from] + cost) {
                    dp[to] = dppre[from] + cost;
                }
            }
            if (dp[dst] != -1) {
                if (res == -1) res = dp[dst];
                else res = min(res, dp[dst]);
            }
            dp.swap(dppre);
            fill(dp.begin(), dp.end(), -1);
        }
        return res;
    }
};
// @lc code=end

