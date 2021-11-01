/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

// @lc code=start
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        vector<vector<int>> &S = coordinates;
        int n = S.size();
        if (n == 2)
            return true;
        for (int i = 2; i < n; i++)
        {
            if (((S[i][1] - S[0][1]) * (S[1][0] - S[0][0])) != ((S[1][1] - S[0][1]) * (S[i][0] - S[0][0])))
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
