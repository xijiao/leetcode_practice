/*
 * @lc app=leetcode id=934 lang=cpp
 *
 * [934] Shortest Bridge
 */

// @lc code=start
static int x = [](){cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); return 0;}();

class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        if (A.size() <= 2) return 1;
        int n = A.size(), m = A[0].size();
        int starti = 0, startj = 0;
        deque<pair<int, int>> l;
        for (int i = 0; l.empty() && i < n; i++) {
            for (int j = 0; l.empty() && j < m; j++) {
                if (A[i][j] == 1) {
                    A[i][j] = 2;
                    l.emplace_back(i, j);
                }
            }
        }
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        deque<pair<int, int>> s;
        while (!l.empty()) {
            auto p = l.front();
            l.pop_front();
            for (int i = 0; i < 4; i++) {
                int x = p.first + dirs[i][0];
                int y = p.second + dirs[i][1];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;

                if (A[x][y] == 1) {
                    l.emplace_back(x, y);
                } else if (A[x][y] == 0) {
                    s.emplace_back(x, y);
                }
                A[x][y] = 2;
            }
        }
        int res = 1;
        while(true) {
            deque<pair<int, int>> ts;
            while (!s.empty()) {
                auto p = s.front();
                cout << p.first << "-" << p.second << " ";
                s.pop_front();
                for (int i = 0; i < 4; i++) {
                    int x = p.first + dirs[i][0];
                    int y = p.second + dirs[i][1];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;

                    if (A[x][y] == 1) {
                        return res;
                    } else if (A[x][y] == 0) {
                        ts.emplace_back(x, y);
                    }
                    A[x][y] = 2;
                }
            }
            ts.swap(s);
            cout << endl;
            res ++;
        }
        return res;
    }
};
// @lc code=end

