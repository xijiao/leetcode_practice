/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        char* strs = "0123456789abcdef";
        string res;
        for (unsigned cur = num; cur; cur >>= 4) {
            res.push_back(strs[cur & 0xf]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

