/*
 * @lc app=leetcode id=713 lang=cpp
 *
 * [713] Subarray Product Less Than K
 */

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0;
        int curSum = 1;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            curSum *= nums[i];
            for (; j <= i && curSum >= k; j++) curSum /= nums[j];
            if (j > i) continue;
            res += (i - j + 1);
        }
        return res;
    }
};
// @lc code=end

