/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int minDiff = arr[n - 1] - arr[0];
        for (int i = 0; i < n - 1 && minDiff > 1; i++)
        {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n - 1; i++)
        {
            if (minDiff == arr[i + 1] - arr[i])
            {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
// @lc code=end
