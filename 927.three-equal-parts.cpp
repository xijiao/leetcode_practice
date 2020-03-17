/*
 * @lc app=leetcode id=927 lang=cpp
 *
 * [927] Three Equal Parts
 */

// @lc code=start
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        for (int i = 0, j = A.size() - 1; i < j; i++, j--) {
            bool bad = false;
            for (int k = i; k >= 0; k--) {
                int p = j - 1 - i + k;
                int q = A.size() - 1 - i + k;
                if (p <= i && (A[k] == 1 || A[q] == 1)) {
                    bad = true;
                    break;
                } else if (A[k] != A[p] || A[p] != A[q]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) return {i, j};
        }

        return {-1, -1};
    }
};
// @lc code=end

