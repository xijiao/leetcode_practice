/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 */

// @lc code=start
class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        if (num.size() < 3)
            return false;
        for (int i = 1; i < 12 && i < num.size(); i++)
        {
            for (int j = i + 1; j < num.size(); j++)
            {
                if (check(num, i, j))
                    return true;
            }
        }
        return false;
    }

    bool check(const string &num, int i, int j)
    {
        if ((i > 1 && num[0] == '0') || (j - i > 1 && num[i] == '0'))
            return false;
        long long v1 = stoll(num.substr(0, i)), v2 = stoll(num.substr(i, j - i));
        long long v3 = v1 + v2;
        string v3str = to_string(v3);

        for (int start = j; start < num.size();)
        {
            if (num.substr(start, v3str.size()) != v3str)
                return false;
            v1 = v2;
            v2 = v3;
            v3 = v1 + v2;
            start += v3str.size();
            v3str = to_string(v3);
        }
        return true;
    }
};
// @lc code=end
