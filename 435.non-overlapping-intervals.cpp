/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int res = 0;
        int right = INT_MIN;
        for (const auto& iv : intervals) {
            if (iv[0] >= right) {
                res++;
                right = iv[1];
            }
        }
        return intervals.size() - res;
    }
};
// @lc code=end

