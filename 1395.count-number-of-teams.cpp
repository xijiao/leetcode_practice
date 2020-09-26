/*
 * @lc app=leetcode id=1395 lang=cpp
 *
 * [1395] Count Number of Teams
 */

// @lc code=start
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (int j = 0; j < rating.size(); j++) {
            int left_sm = 0, left_bg = 0, right_sm = 0, right_bg = 0;
            for (int i = 0; i < j; i++) {
                if (rating[i] < rating[j]) {
                    left_sm++;
                }
                else if (rating[i] > rating[j]) {
                    left_bg++;
                }
            }
            for (int k = j + 1; k < rating.size(); k++) {
                if (rating[j] < rating[k]) {
                    right_bg++;
                }
                else if (rating[j] > rating[k]) {
                    right_sm++;
                }
            }
            res += (left_sm * right_bg);
            res += (left_bg * right_sm);
        }
        return res;
    }
};
// @lc code=end

