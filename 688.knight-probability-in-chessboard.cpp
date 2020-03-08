/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        unordered_map<int, double> cache;
        cache.reserve(N * N * K);
        return dfs(N, K, r, c, cache);
    }

    double dfs(int N, int K, int r, int c,
            unordered_map<int, double>& cache) {
        if (r < 0 || c < 0 || r >= N || c >= N) return 0.0;
        else if (K == 0) return 1.0;
        int key = K << 16 | r << 8 | c;
        if (cache.find(key) != cache.end()) return cache[key];
        double res= 0;
        int dirs[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                {1, -2}, {2, -1}, {2, 1}, {1, 2}};
        for (int i = 0; i < 8; i++) {
            res += dfs(N, K - 1, r + dirs[i][0], c + dirs[i][1], cache) * 0.125;
        }
        cache[key] = res;
        return res;
    }
};
// @lc code=end

