/*
 * @lc app=leetcode id=1326 lang=cpp
 *
 * [1326] Minimum Number of Taps to Open to Water a Garden
 */

// @lc code=start
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> rg;
        for (int i = 0; i <= n; i++) {
            rg.emplace_back(i - ranges[i], i + ranges[i]);
        }
        sort(rg.begin(), rg.end());
        int res = 0;
        for (int start = 0, end = 0, i = 0; start < n; start = end, res++) {
            for (; i <= n && rg[i].first <= start; i++) {
                end = max(end, rg[i].second);
            }
            if (start == end) return -1;
        }
        return res;
    }
};
// @lc code=end

