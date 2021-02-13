/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] ) return 0;
        obstacleGrid[0][0] = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int& v = obstacleGrid[i][j];
                if (v > 0) continue;
                if (i > 0 && obstacleGrid[i - 1][j] < 0) v += obstacleGrid[i - 1][j];
                if (j > 0 && obstacleGrid[i][j - 1] < 0) v += obstacleGrid[i][j - 1];
            }
        }
        return obstacleGrid[n - 1][m - 1] * -1;
    }
};
// @lc code=end

