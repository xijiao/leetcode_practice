/*
 * @lc app=leetcode id=1840 lang=cpp
 *
 * [1840] Maximum Building Height
 */

// @lc code=start
class Solution
{
public:
    int maxBuilding(int n, vector<vector<int>> &r)
    {
        r.push_back({1, 0});
        r.push_back({n, n - 1});
        sort(r.begin(), r.end());
        visit(r);
        reverse(r.begin(), r.end());
        return visit(r);
    }

    int visit(vector<vector<int>> &r)
    {
        int res = 0;
        for (int i = 0; i < r.size() - 1; i++)
        {
            auto &h1 = r[i], &h2 = r[i + 1];
            h2[1] = min(h2[1], h1[1] + abs(h2[0] - h1[0]));
            int maxHeight = (h1[1] + h2[1] + abs(h2[0] - h1[0])) / 2;
            res = max(res, maxHeight);
        }
        return res;
    }
};
// @lc code=end
