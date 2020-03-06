/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        for (int i = 1; i <= num; i++) {
            if (i & 1 == 1) res.push_back(res[i - 1] + 1);
            else res.push_back(res[i >> 1]);
        }
        return res;
    }
};
// @lc code=end

