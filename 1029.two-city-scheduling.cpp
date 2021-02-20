/*
 * @lc app=leetcode id=1029 lang=cpp
 *
 * [1029] Two City Scheduling
 */

// @lc code=start
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int N = costs.size() / 2;
        vector<pair<int,pair<int,int>>> costdiff;
        for (const auto& cost : costs) {
            costdiff.push_back({cost[0] - cost[1], {cost[0], cost[1]}});
        }
        sort(costdiff.begin(), costdiff.end());

        int res = 0;
        for (int i = 0; i < N; i++) {
            res += costdiff[i].second.first;
            res += costdiff[i + N].second.second;
        }
        return res;
    }
};
// @lc code=end

