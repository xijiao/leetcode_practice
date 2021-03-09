/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<uint64_t, int> M;
        int res = 0;
        for (const auto& d : dominoes) {
            uint64_t key;
            if (d[0] > d[1]) key = (uint64_t)d[1] << 32 | d[0];
            else key = (uint64_t)d[0] << 32 | d[1];
            int& v = M[key];
            res += v;
            v++;
        }
        return res;
    }
};
// @lc code=end

