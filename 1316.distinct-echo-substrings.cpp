/*
 * @lc app=leetcode id=1316 lang=cpp
 *
 * [1316] Distinct Echo Substrings
 */

// @lc code=start
class Solution {
public:
    int distinctEchoSubstrings(string text) {
        const int MOD = 1000000007;
        unordered_set<string> res;
        for (int i = 0; i < text.size(); i++) {
            int64_t lh = 0;
            int64_t rh = 0;
            int64_t base = 1;
            for (int w = 1; i + 2 * w <= text.size(); w++) {
                lh = (lh * 26 + (text[i + w - 1] - 'a')) % MOD;
                rh = (rh * 26 + (text[i + 2 * w - 2] - 'a')) % MOD;
                rh = ((rh - (text[i + w - 1] - 'a') * base) % MOD + MOD) % MOD;
                rh = (rh * 26 + (text[i + 2 * w - 1] - 'a')) % MOD;
                //cout << lh << " " << rh << endl;
                if (lh == rh) {
                    string l = text.substr(i, w);
                    string r = text.substr(i + w, w);
                    if (l == r) res.insert(l);
                }
                base = (base * 26) % MOD;
            }
        }
        return res.size();
    }
};
// @lc code=end

