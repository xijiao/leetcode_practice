/*
 * @lc app=leetcode id=738 lang=cpp
 *
 * [738] Monotone Increasing Digits
 */

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        for (int i = 0; i < s.size();)
        {
            if (i < s.size() - 1 && s[i] > s[i + 1])
            {
                int k = i;
                for (; k > 0 && s[k] == s[k - 1]; k--)
                    ;
                s[k] -= 1;
                for (int j = k + 1; j < s.size(); j++)
                {
                    s[j] = '9';
                }
                break;
            }
            else
            {
                i++;
            }
        }
        return stoi(s);
    }
};
// @lc code=end
