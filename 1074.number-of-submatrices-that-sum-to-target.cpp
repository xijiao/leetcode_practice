/*
 * @lc app=leetcode id=1074 lang=cpp
 *
 * [1074] Number of Submatrices That Sum to Target
 */

// @lc code=start
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                unordered_map<int, int> map;
                int sum = 0;
                for (int k = 0; k < m; k++) {
                    sum += (matrix[k][j] - (i == 0 ? 0 : matrix[k][i - 1]));
                    if (sum == target) res++;
                    auto it = map.find(sum - target);
                    if (it != map.end()) res += it->second;
                    map[sum] ++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

