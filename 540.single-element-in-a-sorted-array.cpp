/*
 * @lc app=leetcode id=540 lang=cpp
 *
 * [540] Single Element in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            m -= (m & 1);
            if (nums[m] == nums[m + 1]) l = m + 2;
            else r = m;
        }
        return nums[l];
    }
};
// @lc code=end

