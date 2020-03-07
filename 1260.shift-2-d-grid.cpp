/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k %= (m * n);
        if (k == 0) return grid;
        vector<vector<int>> grid2(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int t = (i * n + j + k) % (m * n);
                int ni = t / n;
                int nj = t % n;
                grid2[ni][nj] = grid[i][j];
            }
        }
        return grid2;
    }
};
// @lc code=end

