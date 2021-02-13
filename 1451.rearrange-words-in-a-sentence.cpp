/*
 * @lc app=leetcode id=1451 lang=cpp
 *
 * [1451] Rearrange Words in a Sentence
 */

// @lc code=start
class Solution {
public:
    string arrangeWords(string text) {
        text[0] = tolower(text[0]);
        stringstream si(text);
        map<int, string> m;
        string cur;
        while (si >> cur) {
            //cout << cur << endl;
            m[cur.size()] += cur + " ";
        }

        stringstream so;
        for (const auto& p : m) {
            so << p.second;
        }
        string res = so.str();
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};
// @lc code=end

