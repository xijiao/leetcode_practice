/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
class Solution {
    static constexpr int DIRS[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, find(matrix, i, j, dp));
            }
        }
        return res;
    }

    bool inboards(vector<vector<int>>& matrix, int x, int y) {
        int m = matrix.size(), n = matrix[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int find(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dp) {
        if (dp[x][y] > 0) return dp[x][y];
        int res = 1;
        for (int i = 0; i < 4; i++) {
            int x2 = x + DIRS[i][0];
            int y2 = y + DIRS[i][1];
            if (inboards(matrix, x2, y2) && matrix[x2][y2] < matrix[x][y]) {
                res = max(res, find(matrix, x2, y2, dp) + 1);
            }
        }
        dp[x][y] = res;
        return res;
    }
};
// @lc code=end

