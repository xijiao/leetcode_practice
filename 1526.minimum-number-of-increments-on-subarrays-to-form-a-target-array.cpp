/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int pre = 0, res = 0;
        for (int v : target)
        {
            if (v > pre)
                res += (v - pre);
            pre = v;
        }
        return res;
    }
};
// @lc code=end
