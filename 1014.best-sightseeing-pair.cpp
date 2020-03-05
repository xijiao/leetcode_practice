/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int max = -2000;
        int t = A[0];
        for (int i = 1; i < A.size(); i++) {
            int v = A[i] - i + t;
            if (v > max) max = v;
            if (A[i] + i > t) t = A[i] + i;
        }
        return max;
    }
};
// @lc code=end

