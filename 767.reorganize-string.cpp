/*
 * @lc app=leetcode id=767 lang=cpp
 *
 * [767] Reorganize String
 */

// @lc code=start
class Solution
{
public:
    string reorganizeString(string s)
    {
        int n = s.size();
        unordered_map<int, int> count;
        for (char c : s)
            count[c]++;

        auto comp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> Q(comp);
        for (const auto &c : count)
            Q.push(c);
        if (Q.top().second > (n + 1) / 2)
            return "";

        string res;
        res.reserve(n);
        while (!Q.empty())
        {
            auto cur = Q.top();
            Q.pop();
            if (res.empty() || res.back() != cur.first)
            {
                res.push_back(cur.first);
            }
            else
            {
                auto cur2 = Q.top();
                Q.pop();
                res.push_back(cur2.first);
                res.push_back(cur.first);
                if (cur2.second > 1)
                    Q.push({cur2.first, cur2.second - 1});
            }
            if (cur.second > 1)
                Q.push({cur.first, cur.second - 1});
        }
        return res;
    }
};
// @lc code=end
