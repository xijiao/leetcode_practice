/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<vector<int>>> T;
        for (const auto& t : times) {
            T[t[0]].push_back({t[1], t[2]});
        }

        unordered_map<int, int> M;
        unordered_set<int> next;
        M[K] = 0;
        next.insert(K);
        for (; !next.empty();) {
            int c = *next.begin();
            next.erase(next.begin());
            int ct = M[c];
            const auto& TL = T[c];
            for (const auto& tl : TL) {
                if (!M.count(tl[0]) || ct + tl[1] < M[tl[0]]) {
                    M[tl[0]] = ct + tl[1];
                    next.insert(tl[0]);
                }
            }
        }
        if (M.size() != N) return -1;
        int res = 0;
        for (const auto& m : M) {
            res = max(res, m.second);
        }
        return res;
    }
};
// @lc code=end

