/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int res = 0;
        for (int l = 0, r = 2; r < nums.size(); r++) {
            while (l < r - 1 && nums[l + 1] - nums[l] != nums[r] - nums[r - 1]) l++;
            if (r - l >= 2) res += (r - l - 1);
        }
        return res;
    }
};
// @lc code=end

