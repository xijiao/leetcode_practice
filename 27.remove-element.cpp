/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for (int n : nums) {
            if (n != val) {
                nums[count++] = n;
            }
        }
        return count;
    }
};
// @lc code=end

