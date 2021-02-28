/*
 * @lc app=leetcode id=1293 lang=cpp
 *
 * [1293] Shortest Path in a Grid with Obstacles Elimination
 */

// @lc code=start
class Solution {
public:
    static constexpr int DIRS[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPath(vector<vector<int>>& grid, int K) {
        int m = grid.size();
        int n = grid[0].size();
        int minSteps = m + n - 2, maxObstacles = minSteps - 1, minStepsForNextRound = minSteps;
        if (maxObstacles <= K) return minSteps;

        vector<int> visited(n * m, -1); // x * n + y -> k left
        queue<vector<int>> q;
        int res = 0;
        q.push({0,0,K});
        visited[0] = K;
        while (!q.empty()) {
            res++;
            minSteps = minStepsForNextRound;
            for (int count = q.size(); count > 0; count--) {
                vector<int> cur = q.front();
                q.pop();
                int x = cur[0];
                int y = cur[1];
                int k = cur[2];
                for (int i = 0; i < 4; i++) {
                    int nx = x + DIRS[i][0];
                    int ny = y + DIRS[i][1];
                    int nk = k;
                    if (!isInbound(grid, nx, ny)) continue;
                    if (grid[nx][ny] == 1) nk--;
                    if (nk < 0) continue;
                    if (visited[nx * n + ny] >= nk) continue;

                    int stepsToTarget = m - nx + n - ny - 2;
                    if (stepsToTarget <= nk && stepsToTarget == minSteps - 1) return res + stepsToTarget;
                    minStepsForNextRound = min(minStepsForNextRound, stepsToTarget);

                    visited[nx * n + ny] = nk;
                    q.push({nx, ny, nk});
                }
            }
        }
        return -1;
    }

    int toVisitedKey(int x, int y, int k) {
        return x << 24 | y << 16 | k;
    }

    bool isInbound(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }

};
// @lc code=end

