/*
 * @lc app=leetcode id=1267 lang=cpp
 *
 * [1267] Count Servers that Communicate
 */

// @lc code=start
class Solution {
    unordered_map<int, int> U;
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                uni(i, ~j);
            }
        }
        unordered_map<int, int> union_count;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) continue;
                union_count[find(i)]++;
            }
        }
        int res = 0;
        for (const auto& uc : union_count) {
            if (uc.second > 1) res += uc.second;
        }
        return res;
    }

    int find(int x) {
        if (!U.count(x)) {
            U[x] = x;
        }
        if (U[x] != x) {
            U[x] = find(U[x]);
        }
        return U[x];
    }

    void uni(int a, int b) {
        a = find(a);
        b = find(b);
        U[a] = b;
    }
};
// @lc code=end

