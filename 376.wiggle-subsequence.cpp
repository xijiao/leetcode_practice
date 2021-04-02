/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int res = 1;
        int state = 0; // 1=up, 0=start, -1=down
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (last == nums[i]) {
                //state = 0;
            }
            else if (last < nums[i]) {
                if (state != 1) res++;
                last = nums[i];
                state = 1;
            } else {
                if (state != -1) res++;
                last = nums[i];
                state = -1;
            }
        }
        return res;
    }
};
// @lc code=end

