/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto it = prev(nums.end(), k % nums.size());
        reverse(nums.begin(), it);
        reverse(it, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

