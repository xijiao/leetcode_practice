/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int l = 0, r;
        vector<vector<int>> res;
        for (r = 1; r < s.size(); r++)
        {
            if (s[l] == s[r])
                continue;
            if (r - l >= 3)
            {
                res.push_back({l, r - 1});
            }
            l = r;
        }
        if (r - l >= 3)
        {
            res.push_back({l, r - 1});
        }
        return res;
    }
};
// @lc code=end
