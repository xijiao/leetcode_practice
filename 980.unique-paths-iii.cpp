/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int totalSteps = 0;
        int starti = 0, startj = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int v = grid[i][j];
                if (v == 1) {
                    starti = i;
                    startj = j;
                } else if (v != -1) {
                    totalSteps++;
                }
            }
        }
        return dfs(grid, starti, startj, totalSteps, 0);
    }

    int dfs(vector<vector<int>>& grid, int i, int j, int totalSteps,
            int steps) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        int v = grid[i][j];
        if (v == 2) return steps == totalSteps ? 1 : 0;
        if (v == -1) return 0;
        grid[i][j] = -1;
        int res = dfs(grid, i - 1, j, totalSteps, steps + 1) +
                dfs(grid, i, j - 1, totalSteps, steps + 1) +
                dfs(grid, i + 1, j, totalSteps, steps + 1) +
                dfs(grid, i, j + 1, totalSteps, steps + 1);
        grid[i][j] = v;
        return res;
    }
};
// @lc code=end

