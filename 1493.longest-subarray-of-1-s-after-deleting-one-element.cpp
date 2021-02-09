/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;
        int zerocount = nums[0] == 1 ? 0 : 1;
        int res = 0;
        for (r = 1; r < nums.size(); r++) {
            if (nums[r] == 0) {
                zerocount++;
            }
            while (zerocount > 1) {
                if (nums[l++] == 0) zerocount--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};
// @lc code=end

