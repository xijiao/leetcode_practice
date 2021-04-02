/*
 * @lc app=leetcode id=1519 lang=cpp
 *
 * [1519] Number of Nodes in the Sub-Tree With the Same Label
 */

// @lc code=start
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> M;
        for (const vector<int>& edge : edges) {
            M[edge[0]].push_back(edge[1]);
            M[edge[1]].push_back(edge[0]);
        }
        vector<int> res(n);
        vector<int> count(26);
        dfs(res, 0, M, labels, count);
        return res;
    }

    void dfs(vector<int>& res, int i,
            unordered_map<int, vector<int>>& M, const string& labels, vector<int>& count) {
        res[i]++;
        count[labels[i] - 'a']++;
        for (int c : M[i]) {
            if (res[c] > 0) continue;
            vector<int> ccount(26);
            dfs(res, c, M, labels, ccount);
            for (int i = 0; i < 26; i++) {
                count[i] += ccount[i];
            }
        }
        res[i] = count[labels[i] - 'a'];
    }
};
// @lc code=end

