/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int used = 0;
        int res = 0;
        for (int i = 0, j = 0; j < A.size(); j++) {
            if (A[j] == 1) {
                res = max(res, j - i + 1);
            } else if (used < K) {
                used ++;
                res = max(res, j - i + 1);
            } else {
                while (i < j && A[i] == 1) {
                    i++;
                }
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

