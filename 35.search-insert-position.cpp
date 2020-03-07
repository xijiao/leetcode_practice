/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int lo = 0, hi = nums.size();
        for (; lo < hi; ) {
            int k = lo + (hi - lo) / 2;
            if (nums[k] >= target) {
                hi = k;
            } else {
                lo = k + 1;
            }
        }
        return lo;
    }
};
// @lc code=end

