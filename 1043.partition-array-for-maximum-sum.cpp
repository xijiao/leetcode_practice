/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 */

// @lc code=start
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n);

        int curMax = arr[0];
        for (int i = 0; i < k; i++)
        {
            curMax = max(curMax, arr[i]);
            dp[i] = curMax * (i + 1);
        }

        for (int i = k; i < n; i++)
        {
            curMax = arr[i];
            for (int j = 0; j < k; j++)
            {
                curMax = max(curMax, arr[i - j]);
                dp[i] = max(dp[i], dp[i - j - 1] + curMax * (j + 1));
            }
        }

        return dp[n - 1];
    }
};
// @lc code=end
