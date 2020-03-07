/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

// @lc code=start
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> res;
        int lo = 0, hi = S.size();
        for (char c : S) {
            if (c == 'I') res.push_back(lo++);
            else res.push_back(hi--);
        }
        res.push_back(lo);
        return res;
    }
};
// @lc code=end

