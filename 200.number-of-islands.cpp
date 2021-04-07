/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
    static constexpr int DIRS[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    paint(grid, i, j);
                }
            }
        }
        return res;
    }

    void paint(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int x2 = x + DIRS[i][0];
            int y2 = y + DIRS[i][1];
            if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] != '1') continue;
            paint(grid, x2, y2);
        }
    }
};
// @lc code=end

