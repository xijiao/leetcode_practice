/*
 * @lc app=leetcode id=1637 lang=cpp
 *
 * [1637] Widest Vertical Area Between Two Points Containing No Points
 */

// @lc code=start
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        unordered_set<int> found;
        vector<int> X;
        for (auto &p : points)
        {
            if (found.count(p[0]))
                continue;
            X.push_back(p[0]);
            found.insert(p[0]);
        }
        sort(X.begin(), X.end());
        int n = X.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            res = max(res, X[i + 1] - X[i]);
        }
        return res;
    }
};
// @lc code=end
