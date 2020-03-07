/*
 * @lc app=leetcode id=1368 lang=cpp
 *
 * [1368] Minimum Cost to Make at Least One Valid Path in a Grid
 */

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        deque<tuple<int, int, int>> q;
        q.emplace_back(0, 0, 0);

        while (!q.empty()) {
            tuple<int, int, int> cur = q.front();
            q.pop_front();
            int x = get<0>(cur);
            int y = get<1>(cur);
            int cost = get<2>(cur);
            if (visited[x][y]) continue;
            visited[x][y] = true;

            if (x == m - 1 && y == n - 1) return cost;

            for (int i = 0; i < 4; i++) {
                int nx = x + DIRS[i][0];
                int ny = y + DIRS[i][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (grid[x][y] == i + 1) {
                    q.emplace_front(nx, ny, cost);
                } else {
                    q.emplace_back(nx, ny, cost + 1);
                }
            }
        }

        return -1;
    }

};
// @lc code=end

