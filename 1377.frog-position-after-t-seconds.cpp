/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 */

// @lc code=start
class Solution
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        unordered_map<int, unordered_set<int>> M;
        for (auto &edge : edges)
        {
            M[edge[0]].insert(edge[1]);
            M[edge[1]].insert(edge[0]);
        }

        return dfs(M, t, target, -1, 1);
    }

    double dfs(unordered_map<int, unordered_set<int>> &M, int t, int target, int pre, int cur)
    {
        if (t < 0)
            return 0;
        int pathcount = M[cur].size();
        if (cur == target)
        {
            if (t == 0 || pathcount == 0 || (cur != 1 && pathcount == 1))
                return 1;
            else
                return 0;
        }

        if (pathcount == 1 && cur != 1)
            return 0;

        for (int path : M[cur])
        {
            if (path == pre)
                continue;
            double res = dfs(M, t - 1, target, cur, path);
            if (res > 0)
                return res / (pathcount - (cur == 1 ? 0 : 1));
        }
        return 0;
    }
};
// @lc code=end
