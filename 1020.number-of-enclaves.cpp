/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 */

// @lc code=start
class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        int lands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == 1) {
                    int w = walk(A, i, j);
                    if (w != -1) lands += w;
                }
            }
        }
        return lands;
    }

    int walk(vector<vector<int>>& A, int i, int j) {
        const int DIRS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size()) return -1;
        if (A[i][j] != 1) return 0;
        A[i][j] = -1;
        int res = 1;
        bool out = false;
        for (int k = 0; k < 4; k++) {
            int x = i + DIRS[k][0];
            int y = j + DIRS[k][1];
            int w = walk(A, x, y);
            if (w == -1) out = true;
            else res += w;
        }
        return out ? -1 :res;
    }
};
// @lc code=end

