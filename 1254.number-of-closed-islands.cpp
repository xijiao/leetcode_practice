/*
 * @lc app=leetcode id=1254 lang=cpp
 *
 * [1254] Number of Closed Islands
 */

// @lc code=start
class Solution {
    static constexpr int DIRS[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && paint(grid, i, j)) {
                    res++;
                }
            }
        }
        return res;
    }

    bool paint(vector<vector<int>>& grid, int x, int y) {
        int n = grid.size(), m = grid[0].size();
        int res = true;
        grid[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int x1 = x + DIRS[i][0];
            int y1 = y + DIRS[i][1];
            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) {
                res = false;
            } else if (grid[x1][y1] == 0) {
                res = paint(grid, x1, y1) & res;
            }
        }
        return res;
    }
};
// @lc code=end

