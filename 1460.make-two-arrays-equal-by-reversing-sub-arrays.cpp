/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
 */

// @lc code=start
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        int n = target.size();
        unordered_map<int, int> m1, m2;
        for (int i = 0; i < n; i++)
        {
            m1[target[i]]++;
            m2[arr[i]]++;
        }
        return m1 == m2;
    }
};
// @lc code=end
