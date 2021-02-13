/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0], curMax = nums[0], curMin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int v = nums[i];
            int newCurMax = max(max(curMax * v, curMin * v), v);
            int newCurMin = min(min(curMax * v, curMin * v), v);
            curMax = newCurMax;
            curMin = newCurMin;
            res = max(res, curMax);
        }
        return res;
    }
};
// @lc code=end

