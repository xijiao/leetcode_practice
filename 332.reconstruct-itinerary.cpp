/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

// @lc code=start
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        int n = tickets.size();
        unordered_map<string, multiset<string>> DIR;
        for (const auto &ticket : tickets)
        {
            DIR[ticket[0]].insert(ticket[1]);
        }
        vector<string> res;
        res.reserve(n + 1);
        visit(DIR, res, "JFK");
        reverse(res.begin(), res.end());
        return res;
    }

    void visit(unordered_map<string, multiset<string>> &DIR, vector<string> &res, const string &cur)
    {
        multiset<string> &D = DIR[cur];
        while (!D.empty())
        {
            string next = *D.begin();
            D.erase(D.begin());
            visit(DIR, res, next);
        }
        res.push_back(cur);
    }
};
// @lc code=end
