/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        for (; lo < hi;) {
            // cout << lo << " " << hi << " ";
            int mi = (lo + hi) / 2;
            int count = countLE(matrix, mi);
            // cout << count  << endl;
            if (count < k) lo = mi + 1;
            else hi = mi;
        }
        return lo;
    }

    int countLE(vector<vector<int>>& matrix, int v) {
        int n = matrix.size(), i = 0, j = n - 1;
        int res = 0;
        for (; j >= 0 && i < n;) {
            if (matrix[i][j] > v) {
                j--;
            } else {
                res += (j + 1);
                // cout << j << endl;
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

