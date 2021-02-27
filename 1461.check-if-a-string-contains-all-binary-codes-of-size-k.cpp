/*
 * @lc app=leetcode id=1461 lang=cpp
 *
 * [1461] Check If a String Contains All Binary Codes of Size K
 */

// @lc code=start
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        vector<bool> found(pow(2, k), false);
        int cur = 0;
        for (int i = 0; i < s.size(); i++) {
            cur <<= 1;
            if (s[i] == '1') cur |= 1;
            if (i >= k - 1) {
                found[cur] = true;
                cur &= ~(1 << (k - 1));
            }
        }
        for (bool b : found) {
            if (!b) return false;
        }
        return true;
    }
};
// @lc code=end

