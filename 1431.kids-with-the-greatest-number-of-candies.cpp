/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxCandies = 0, n = candies.size();
        for (int c : candies)
            maxCandies = max(maxCandies, c);

        vector<bool> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = candies[i] + extraCandies >= maxCandies;
        }
        return res;
    }
};
// @lc code=end
