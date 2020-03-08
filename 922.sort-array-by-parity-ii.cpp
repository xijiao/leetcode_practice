/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        for (int i = 0, j = 1; i < A.size() - 1;) {
            if (A[i] % 2 == 0) {
                i += 2;
            } else {
                swap(A[i], A[j]);
                j += 2;
            }
        }
        return A;
    }
};
// @lc code=end

