/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<int, int> M;
        unordered_set<int> mapped;
        for (int i = 0; i < s.size(); i++)
        {
            char sc = s[i], tc = t[i];
            if (M.count(sc) == 0)
            {
                if (mapped.count(tc))
                {
                    return false;
                }
                M[sc] = tc;
                mapped.insert(tc);
            }
            else if (M[sc] != tc)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
