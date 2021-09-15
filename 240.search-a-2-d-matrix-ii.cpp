/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    // bool searchMatrix(vector<vector<int>>& matrix, int target) {
    //     int m = matrix.size(), n = matrix[0].size();
    //     for (int i = 0, j = 0; i >= 0 && i < m && j >= 0 && j < n;) {
    //         if (matrix[i][j] == target) return true;
    //         else if (matrix[i][j] > target) j--;
    //         else if (j < n - 1 && matrix[i][j + 1] <= target) j++;
    //         else i++;
    //     }
    //     return false;
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0, j = n - 1; i < m && j >= 0;) {
            if (matrix[i][j] == target) return true;
            matrix[i][j] > target ? j-- : i++;
        }
        return false;
    }
};
// @lc code=end

