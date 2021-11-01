/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

// @lc code=start
class Solution
{
public:
    int maxScore(string s)
    {
        int zeros = 0, ones = 0;
        for (char c : s)
        {
            if (c == '1')
                ones++;
        }

        int res = 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (s[i] == '1')
                ones--;
            else
                zeros++;
            res = max(res, zeros + ones);
        }
        return res;
    }
};
// @lc code=end
