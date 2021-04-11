/*
 * @lc app=leetcode id=1365 lang=cpp
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101] = {0};
        vector<int> res(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            int v = nums[i];
            count[v]++;
        }
        for (int i = nums.size() - 1; i >= 0; --i) {
            int v = nums[i];
            for (int j = 0; j < v; j++) {
                res[i] += count[j];
            }
        }
        return res;
    }
};
// @lc code=end

