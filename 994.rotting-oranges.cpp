/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int DIRS[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int m = grid.size(), n = grid[0].size();
        deque<pair<int, int>> q;
        int left = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.emplace_back(i, j);
                else if (grid[i][j] == 1) left++;
            }
        }     
        int res = 0;
        while (left && !q.empty()) {
            for (int count = q.size(); count > 0; count--) {
                auto p = q.front(); q.pop_front();
                for (int k = 0; k < 4; k++) {
                    int x = p.first + DIRS[k][0];
                    int y = p.second + DIRS[k][1];
                    if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2) continue;
                    grid[x][y] = 2;
                    left--;
                    q.emplace_back(x, y);
                }
            }
            res++;
        }
        return left > 0 ? -1 : res;
    }
};
// @lc code=end

