/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(),
            [](const vector<int>& a, const vector<int>& b) {return a[1] < b[1];});
        int pointCut = points[0][1];
        int cutTimes = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] <= pointCut) continue;
            pointCut = points[i][1];
            cutTimes++;
        }
        return cutTimes;
    }
};
// @lc code=end

