/*
 * @lc app=leetcode id=1129 lang=cpp
 *
 * [1129] Shortest Path with Alternating Colors
 */

// @lc code=start
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        unordered_map<int, vector<int>> RM, BM;
        for (const auto& edge : red_edges) RM[edge[0]].push_back(edge[1]);
        for (const auto& edge : blue_edges) BM[edge[0]].push_back(edge[1]);
        unordered_set<int> visited;
        queue<pair<int, bool>> q; // node, red/blue
        q.push({0, false});
        q.push({0, true});
        visited.insert(0);
        vector<int> res(n, -1);
        res[0] = 0;
        int step = 0;
        while (!q.empty()) {
            step++;
            for (int count = q.size(); count > 0; count--) {
                auto cur = q.front();
                q.pop();
                unordered_map<int, vector<int>>* M = nullptr;
                if (cur.second) M = &BM;
                else M = &RM;
                for (int end : (*M)[cur.first]) {
                    if (res[end] == -1) res[end] = step;
                    bool color = !cur.second;
                    int key = color ? end : end * -1;
                    if (visited.count(key)) continue;
                    visited.insert(key);
                    q.push({end, color});
                }
            }
        }
        return res;
    }
};
// @lc code=end

