/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, m = strs.size(), n = strs[0].size();
        for (int col = 0; col < n; col++) {
            for (int row = 1; row < m; row++) {
                if (strs[row - 1][col] > strs[row][col]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};
// @lc code=end

