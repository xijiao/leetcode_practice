/*
 * @lc app=leetcode id=1559 lang=cpp
 *
 * [1559] Detect Cycles in 2D Grid
 */

// @lc code=start
class Solution {
    static constexpr int DIRS[][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                if (paint(grid, i, j, grid[i][j])) return true;
            }
        }
        return false;
    }

    bool inBoard(vector<vector<char>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool paint(vector<vector<char>>& grid, int i, int j, char color) {
        queue<pair<int, int>> q;
        q.push({i, j});

        for (;!q.empty();) {
            unordered_set<int> round_set;
            for (int c = q.size(); c > 0; c--) {
                pair<int, int> front = q.front();
                q.pop();
                int x = front.first;
                int y = front.second;
                grid[x][y] = 0;
                for (int k = 0; k < 4; k++) {
                    int x1 = x + DIRS[k][0];
                    int y1 = y + DIRS[k][1];
                    if (!inBoard(grid, x1, y1)) continue;
                    if (grid[x1][y1] != color) continue;
                    if (round_set.count(x1 << 16 | y1)) return true;
                    round_set.insert(x1 << 16 | y1);
                    q.push({x1, y1});
                }
            }
        }

        return false;
    }
};
// @lc code=end

