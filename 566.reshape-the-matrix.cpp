/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if (n * m != r * c) return nums;

        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = ((i * m) + j) / c;
                int y = ((i * m) + j) % c;
                res[x][y] = nums[i][j];
            }
        }
        return res;
    }
};
// @lc code=end

