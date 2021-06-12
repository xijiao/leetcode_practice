/*
 * @lc app=leetcode id=1253 lang=cpp
 *
 * [1253] Reconstruct a 2-Row Binary Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int total = 0, sum2count = 0;
        for (int cs : colsum) {
            total += cs;
            if (cs == 2) sum2count++;
        }
        if (upper + lower != total || upper < sum2count || lower < sum2count) return {};

        vector<vector<int>> res(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int cs = colsum[i];
            if (cs != 2) continue;
            res[0][i] = 1;
            res[1][i] = 1;
            upper--;
            lower--;
        }
        for (int i = 0; i < n; i++) {
            int cs = colsum[i];
            if (cs == 0 || cs == 2) continue;
            if (upper > 0) {
                res[0][i] = 1;
                upper--;
            } else {
                res[1][i] = 1;
                lower--;
            }
        }
        return res;
    }
};
// @lc code=end

