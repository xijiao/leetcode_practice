/*
 * @lc app=leetcode id=1010 lang=cpp
 *
 * [1010] Pairs of Songs With Total Durations Divisible by 60
 */

// @lc code=start
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int d[60] = {0};
        int res = 0;
        for (int t : time) {
            t %= 60;
            res += d[(60 - t) % 60];
            d[t] ++;
        }
        return res;
    }
};
// @lc code=end

