/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

// @lc code=start
class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        for (int i = s.size() - 1; i >= 0;) {
            if (s[i] == '#') {
                char v = (s[i - 2] - '1') * 10 + (s[i - 1] - '0') + 'j';
                res.push_back(v);
                i -= 3;
            } else {
                char v = (s[i] - '1') + 'a';
                res.push_back(v);
                i--;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

