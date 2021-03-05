/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        for (int i = 1; i < A.size(); i++) {
            A[i] += A[i - 1];
        }

        int res = A[L + M - 1];
        int LMax = A[L - 1];
        int MMax = A[M - 1];
        for (int i = L + M; i < A.size(); i++) {
            LMax = max(LMax, A[i - M] - A[i - M - L]);
            MMax = max(MMax, A[i - L] - A[i - M - L]);
            res = max(res, max(LMax + A[i] - A[i - M], MMax + A[i] - A[i - L]));
        }
        return res;
    }
};
// @lc code=end

