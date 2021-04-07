/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxv = nums[0];
        for (int v : nums) maxv = max(maxv, v);
        int l = 1, r = maxv;
        for (; l < r; ) {
            int m = (l + r) / 2;
            if (divideAndSum(nums, m) <= threshold) r = m;
            else l = m + 1;
        }
        return l;
    }

    int divideAndSum(vector<int>& nums, int divider) {
        int res = 0;
        for (int v : nums) {
            res += (v / divider + (v % divider ? 1 : 0));
        }
        return res;
    }
};
// @lc code=end

