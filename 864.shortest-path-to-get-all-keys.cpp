/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
public:
    struct Info {
        int x;
        int y;
        int keys; // bits
    };
    static constexpr int DIRS[][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int shortestPathAllKeys(vector<string>& grid) {
        int startx, starty, totalkeys = 0, m = grid.size(), n = grid[0].size();
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == '@') {
                    startx = x;
                    starty = y;
                } else if (grid[x][y] >= 'a' && grid[x][y] <= 'f') {
                    totalkeys++;
                }
            }
        }
        queue<Info> q;
        q.push({startx, starty, 0});
        unordered_set<string> visited;
        int res = 0;
        while (!q.empty()) {
            for (int count = q.size(); count > 0; count--) {
                Info cur = q.front();
                q.pop();
                int x = cur.x, y = cur.y, keys = cur.keys;
                char c = grid[x][y];
                if (c >= 'a' && c <= 'f') {
                    keys |= (1 << (c - 'a'));
                }
                if (keys == ((1 << totalkeys) - 1)) return res;
                if (c >= 'A' && c <= 'F') {
                    if (!(keys & (1 << (c - 'A')))) continue;
                }
                for (int i = 0; i < 4; i++) {
                    int x1 = x + DIRS[i][0];
                    int y1 = y + DIRS[i][1];
                    if (!inbounds(grid, x1, y1)) continue;
                    if (grid[x1][y1] == '#') continue;
                    string visitkey = to_string(keys) + "#" + to_string(x1) + "#" + to_string(y1);
                    if (visited.count(visitkey)) continue;
                    visited.insert(visitkey);
                    q.push({x1, y1, keys});
                }
            }
            res++;
        }
        return -1;
    }

    bool inbounds(vector<string>& grid, int x, int y) {
        int m = grid.size(), n = grid[0].size();
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // int find(vector<string>& grid, int x, int y, unordered_set<char>& keys, int totalkeys) {
    //     cout << x << " " << y << endl;
    //     char c = grid[x][y];
    //     if (c >= 'a' && c <= 'f') {
    //         if (keys.size() + 1 >= totalkeys) return 0;
    //         keys.insert(c);
    //     } else if (c >= 'A' && c <= 'F') {
    //         if (!keys.count(c - 'A' + 'a')) return -1;
    //     }
    //     int res = -1;
    //     grid[x][y] = '.';
    //     for (int i = 0; i < 4; i++) {
    //         int x1 = x + DIRS[i][0];
    //         int y1 = y + DIRS[i][1];
    //         if (!inbounds(grid, x1, y1)) continue;
    //         if (grid[x1][y1] == '#') continue; 
    //         int r = find(grid, x + DIRS[i][0], y + DIRS[i][1], keys, totalkeys);
    //         if (r == -1) continue;
    //         if (res == -1) res = r + 1;
    //         else res = min(res, r + 1);
    //     }
    //     grid[x][y] = c;

    //     if (c >= 'a' && c <= 'f') {
    //         keys.erase(c);
    //     }
    //     return res;
    // }
};
// @lc code=end

