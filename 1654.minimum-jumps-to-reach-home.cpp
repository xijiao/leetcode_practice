/*
 * @lc app=leetcode id=1654 lang=cpp
 *
 * [1654] Minimum Jumps to Reach Home
 */

// @lc code=start
class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        if (x == 0)
            return 0;
        unordered_set<int> forbid(forbidden.begin(), forbidden.end());
        unordered_map<int, int> cache;
        deque<vector<int>> Q;
        const int maxLimit = 2000 + b * 2;
        cache[toHashKey(0, 0)] = 0;
        Q.push_back({0, 0, 0});
        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop_front();
            {
                int x1 = cur[0] + a;
                int backcount = 0;
                int steps = cur[2] + 1;
                int key = toHashKey(x1, backcount);
                if (x1 <= maxLimit && !forbid.count(x1) && (!cache.count(key) || cache[key] > steps))
                {
                    if (x1 == x)
                        return steps;
                    cache[key] = steps;
                    Q.push_back({x1, backcount, steps});
                }
            }
            if (cur[0] > b)
            {
                int x2 = cur[0] - b;
                int backcount = cur[1] + 1;
                int steps = cur[2] + 1;
                int key = toHashKey(x2, backcount);
                if (backcount < 2 && !forbid.count(x2) && (!cache.count(key) || cache[key] > steps))
                {
                    if (x2 == x)
                        return steps;
                    cache[key] = steps;
                    Q.push_back({x2, backcount, steps});
                }
            }
        }

        return -1;
    }

    int toHashKey(int x, int back)
    {
        return x << 2 | back;
    }
};
// @lc code=end
