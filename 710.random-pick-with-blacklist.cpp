/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 */

// @lc code=start
class Solution {
    unordered_map<int, int> m;
    int M;
public:
    Solution(int N, vector<int>& blacklist) {
        M = N - blacklist.size();
        unordered_set<int> u;
        for (int i : blacklist) {
            if (i >= M) u.insert(i);
        }

        for (int p = M, i = 0; p < N && i < blacklist.size();) {
            if (u.count(p)) {
                p++;
                continue;
            }
            else if (u.count(blacklist[i])) {
                i++;
                continue;
            }
            m[blacklist[i]] = p;
            p++;
            i++;
        }
        srand(time(nullptr));
    }
    
    int pick() {
        int v = rand() % M;
        if (m.count(v)) return m[v];
        else return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

