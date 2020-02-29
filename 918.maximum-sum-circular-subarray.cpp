/*
 * @lc app=leetcode id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxSum = -30000, curMax = 0, minSum = 30000, curMin = 0;

        for (int i : A) {
            curMax = max(curMax + i, i);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + i, i);
            minSum = min(minSum, curMin);
            total += i;
        }

        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};
// @lc code=end

