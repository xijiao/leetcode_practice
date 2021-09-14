/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int v = matrix[i - 1][j] + matrix[i][j];
                if (j > 0) v = min(v, matrix[i - 1][j - 1] + matrix[i][j]);
                if (j < n - 1) v = min(v, matrix[i - 1][j + 1] + matrix[i][j]);
                matrix[i][j] = v;
            }
        }
        int res = matrix[n - 1][0];
        for (int j = 1; j < n; j++) {
            res = min(res, matrix[n - 1][j]);
        }
        return res;
    }
};
// @lc code=end

