/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 */

// @lc code=start
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.empty()) return 0;
        sort(tokens.begin(), tokens.end());
        int points = 0, i = 0, j = tokens.size() - 1;
        int res = 0;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i++];
                res = max(res, ++points);
            } else if (points > 0) {
                P += tokens[j--];
                points --;
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

