/*
 * @lc app=leetcode id=915 lang=cpp
 *
 * [915] Partition Array into Disjoint Intervals
 */

// @lc code=start
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int leftmax = A[0], allmax = A[0];
        int res = 1, N = A.size();
        for (int i = 1; i < N; i++) {
            allmax = max(allmax, A[i]);
            if (A[i] < leftmax) {
                leftmax = allmax;
                res = i + 1;
            }
        }
        return res;
    }
};
// @lc code=end

