/*
 * @lc app=leetcode id=1131 lang=cpp
 *
 * [1131] Maximum of Absolute Value Expression
 */

// @lc code=start
class Solution
{
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int N = arr1.size(), res = 0;
        for (int p : {-1, 1})
        {
            for (int q : {-1, 1})
            {
                int minSum = arr1[0] * p + arr2[0] * q;
                for (int i = 1; i < N; i++)
                {
                    int cur = arr1[i] * p + arr2[i] * q + i;
                    res = max(res, cur - minSum);
                    //cout << p << " " << q << " " << i << " " << cur << " " << minSum << " " << res << endl;
                    minSum = min(minSum, cur);
                }
            }
        }
        return res;
    }
};
// @lc code=end
