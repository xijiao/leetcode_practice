/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

// @lc code=start
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        unordered_set<int> rows, cols;
        for (const auto& idx : indices) {
            if (rows.find(idx[0]) == rows.end()) rows.insert(idx[0]);
            else rows.erase(idx[0]);
            if (cols.find(idx[1]) == cols.end()) cols.insert(idx[1]);
            else cols.erase(idx[1]);
        }

        return rows.size() * m + cols.size() * n - rows.size() * cols.size() * 2;
    }
};
// @lc code=end

