/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    // Failed: Time Limit Exceeded
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> E;
        for (auto& edge : edges) {
            E[edge[0]].push_back(edge[1]);
            E[edge[1]].push_back(edge[0]);
        }
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            visited.insert(i);
            heights[i] = dfs(n, i, E, visited);
            //visited.erase(i);
        }

        int minheight = heights[0];
        for (int i = 0; i < n; i++) {
            //cout << heights[i] << " ";
            minheight = min(minheight, heights[i]);
        }
        cout << endl;

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (heights[i] == minheight) res.push_back(i);
        }
        return res;
    }

    int dfs(int n, int i, unordered_map<int, vector<int>> E, unordered_set<int>& visited) {
        int res = 1;
        for (int next : E[i]) {
            if (visited.count(next)) continue;
            visited.insert(next);
            res = max(res, 1 + dfs(n, next, E, visited));
            visited.erase(next);
        }
        return res;
    }
};
// @lc code=end

