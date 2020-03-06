/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size() - 1;
        int res = 0;
        while (lo < hi) {
            res = max(res, (hi - lo) * min(height[lo], height[hi]));
            if (height[lo] < height[hi]) lo++;
            else hi--;
        }
        return res;
    }
};
// @lc code=end

