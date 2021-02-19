/*
 * @lc app=leetcode id=1284 lang=cpp
 *
 * [1284] Minimum Number of Flips to Convert Binary Matrix to Zero Matrix
 */

// @lc code=start
class Solution {
    int m;
    int n;
public:
    static constexpr int DIRS[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        int bitmap = fillBitMap(mat);
        if (bitmap == 0) return 0;
        unordered_set<int> visited;
        queue<int> q;
        visited.insert(bitmap);
        q.push(bitmap);
        int res = 0;
        while (!q.empty()) {
            res++;
            for (int count = q.size(); count > 0; count--) {
                int curmap = q.front();
                q.pop();
                for (int x = 0; x < m; x++) {
                    for (int y = 0; y < n; y++) {
                        int nextmap = flipCross(curmap, x, y);
                        if (nextmap == 0) return res;
                        if (visited.count(nextmap)) continue;
                        visited.insert(nextmap);
                        q.push(nextmap);
                    }
                }
            }
        }

        return -1;
    }

    int fillBitMap(const vector<vector<int>>& mat) {
        int res = 0;
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (mat[x][y] == 1) {
                    res |= (1 << (x * n + y));
                }
            }
        }
        return res;
    }

    int flipCross(int bitmap, int x, int y) {
        //cout << bitmap << " ";
        bitmap ^= (1 << (x * n + y));
        for (int i = 0; i < 4; i++) {
            int x1 = x + DIRS[i][0];
            int y1 = y + DIRS[i][1];
            if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n) continue;
            bitmap ^= (1 << (x1 * n + y1));
        }
        //cout << bitmap << endl;
        return bitmap;
    }
};
// @lc code=end

