/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int res = 0;
        int smallsubarr = 0;
        int cursubarr = 0;
        for (int a : A) {
            if (a < L) {
                res += cursubarr;
                smallsubarr++;
            } else if (a <= R) {
                cursubarr += (smallsubarr + 1);
                smallsubarr = 0;
                res += cursubarr;
            } else {
                cursubarr = 0;
                smallsubarr = 0;
            }
        }
        return res;
    }
};
// @lc code=end

