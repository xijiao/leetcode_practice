/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

// @lc code=start
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> score2(score);
        sort(score2.begin(), score2.end(), greater<int>());
        unordered_map<int, int> rank; // score -> rank
        for (int i = 1; i <= score.size(); i++) {
            rank[score2[i - 1]] = i;
        }
        vector<string> res;
        for (int i = 0; i < score.size(); i++) {
            int r = rank[score[i]];
            if (r == 1) {
                res.push_back("Gold Medal");
            } else if (r == 2) {
                res.push_back("Silver Medal");
            } else if (r == 3) {
                res.push_back("Bronze Medal");
            } else {
                res.push_back(to_string(r));
            }
        }
        return res;
    }
};
// @lc code=end

