/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 */

// @lc code=start
class Solution
{
public:
    //Time Limit Exceeded
    //72/98 cases passed (N/A)
    int maxDistance(vector<int> &position, int m)
    {
        int n = position.size();
        sort(position.begin(), position.end());
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 2; i <= n; i++)
        {
            dp[2][i] = position[i - 1] - position[0];
        }

        for (int i = 3; i <= m; i++)
        {
            for (int j = i; j <= n; j++)
            {
                for (int k = i - 1; k < j && position[j - 1] - position[k - 1] > dp[i][j]; k++)
                {
                    dp[i][j] = max(dp[i][j], min(dp[i - 1][k], position[j - 1] - position[k - 1]));
                }
            }
        }
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[m][n];
    }
};
// @lc code=end
