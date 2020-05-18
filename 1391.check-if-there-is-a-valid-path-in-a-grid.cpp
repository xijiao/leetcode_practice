/*
 * @lc app=leetcode id=1391 lang=cpp
 *
 * [1391] Check if There is a Valid Path in a Grid
 */

// @lc code=start
class Solution {
    const int LEFT = 0x1, RIGHT = 0x2, UP = 0x4, DOWN = 0x8;
    const int DIRS[7] = {0, LEFT | RIGHT, UP | DOWN, LEFT | DOWN, RIGHT | DOWN, LEFT | UP, UP | RIGHT};

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        paint(grid, 0, 0);
        return grid[m - 1][n - 1] == 0;
    }

    void paint(vector<vector<int>>& grid, int i, int j) {
        //cout << i << " " << j << endl;
        int m = grid.size(), n = grid[0].size();
        int dir = DIRS[grid[i][j]];
        grid[i][j] = 0;
        if (dir & LEFT && j > 0 && grid[i][j - 1] && DIRS[grid[i][j - 1]] & RIGHT) paint(grid, i, j - 1);
        if (dir & RIGHT && j < n - 1 && grid[i][j + 1] && DIRS[grid[i][j + 1]] & LEFT) paint(grid, i, j + 1);
        if (dir & UP && i > 0 && grid[i - 1][j] && DIRS[grid[i - 1][j]] & DOWN) paint(grid, i - 1, j);
        if (dir & DOWN && i < m - 1 && grid[i + 1][j] && DIRS[grid[i + 1][j]] & UP) paint(grid, i + 1, j);
    }
};
// @lc code=end

