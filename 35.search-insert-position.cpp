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

        int l = 0;
        int r = nums.size() - 1;
        for (;;) {
            if (r <= l) {
                if (nums[l] >= target) return l;
                else return l + 1;
            }
            
            int m = (l + r) / 2;
            if (nums[m] == target) return m;
            else if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return 0;
    }
};
// @lc code=end

