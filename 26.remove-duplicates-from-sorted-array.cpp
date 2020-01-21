/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:

    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[count - 1] != nums[i]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
// @lc code=end

