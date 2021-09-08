/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
    int dp[50][50] = {{0}};
public:
    int minScoreTriangulation(vector<int>& values, int i = 0, int j = 0) {
        if (j == 0) j = values.size() - 1;
        if (dp[i][j] != 0) return dp[i][j];
        int res = 0;
        for (int k = i + 1; k < j; k++) {
            res = min(res == 0 ? INT_MAX : res,
                minScoreTriangulation(values, i, k) +
                values[i] * values[k] * values[j] +
                minScoreTriangulation(values, k, j));
        }
        dp[i][j] = res;
        return res;
    }

};
// @lc code=end

