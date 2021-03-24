/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        unordered_set<int> oddrows, oddcols;
        for (const auto& i : indices) {
            int row = i[0], col = i[1];
            if (oddrows.count(row)) {
                oddrows.erase(row);
            } else {
                oddrows.insert(row);
            }
            if (oddcols.count(col)) {
                oddcols.erase(col);
            } else {
                oddcols.insert(col);
            }
        }
        return oddrows.size() * m + oddcols.size() * n - oddrows.size() * oddcols.size() * 2;
    }
};
// @lc code=end

