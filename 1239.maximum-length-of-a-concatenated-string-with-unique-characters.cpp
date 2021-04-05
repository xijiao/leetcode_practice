/*
 * @lc app=leetcode id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> dp;
        dp.push_back(bitset<26>());
        int res = 0;
        for (const string& s : arr) {
            bitset<26> bs;
            for (char c : s) {
                bs.set(c - 'a');
            }
            if (bs.count() < s.size()) continue;
            for (int i = dp.size() - 1; i >= 0; i--) {
                const auto& d = dp[i];
                if ((bs & d).any()) continue;
                res = max(res, int(bs.count() + d.count()));
                dp.push_back(bs | d);
            }
        }
        return res;
    }
};
// @lc code=end

