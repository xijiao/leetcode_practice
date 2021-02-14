/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

// @lc code=start
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        string pre1, pre2;
        string cur;
        vector<string> res;
        for (; ss >> cur;) {
            if (pre1 == first && pre2 == second) {
                res.push_back(cur);
            }
            pre1 = pre2;
            pre2 = cur;
        }
        return res;
    }
};
// @lc code=end

