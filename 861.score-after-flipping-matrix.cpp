/*
 * @lc app=leetcode id=861 lang=cpp
 *
 * [861] Score After Flipping Matrix
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                toggleRow(A, i);
            }
        }
        for (int col = 1; col < n; col++) {
            int count = 0;
            for (int row = 0; row < m; row++) {
                count += A[row][col];
            }
            if (count < m - count) toggleColumn(A, col);
        }

        int score = 0;
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                score += (1 << (n - 1 - col)) * A[row][col];
            }
        }
        return score;
    }

    void toggleRow(vector<vector<int>>& A, int row) {
        int m = A.size(), n = A[0].size();
        int S[] = {1, 0};
        for (int col = 0; col < n; col++) {
            A[row][col] = S[A[row][col]];
        }
    }

    void toggleColumn(vector<vector<int>>& A, int col) {
        int m = A.size(), n = A[0].size();
        int S[] = {1, 0};
        for (int row = 0; row < m; row++) {
            A[row][col] = S[A[row][col]];
        }
    }
};
// @lc code=end

