/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        bool inserted = false;
        for (const vector<int>& interval : intervals) {
            if (inserted) {
                res.push_back(interval);
            } else if (interval[0] > newInterval[1]) {
                res.push_back(newInterval);
                res.push_back(interval);
                newInterval = {-1, -1};
                inserted = true;
            } else if (!overlap(interval, newInterval)) {
                res.push_back(interval);
            } else {
                merge(interval, newInterval);
            }
        }
        if (!inserted) res.push_back(newInterval);
        return res;
    }

    bool overlap(const vector<int>& a, const vector<int>& b) {
        return !(a[1] < b[0] || b[1] < a[0]);
    }

    void merge(const vector<int>& a, vector<int>& b) {
        b[0] = min(b[0], a[0]);
        b[1] = max(b[1], a[1]);
    }
};
// @lc code=end

