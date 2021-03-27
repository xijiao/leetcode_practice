/*
 * @lc app=leetcode id=1353 lang=cpp
 *
 * [1353] Maximum Number of Events That Can Be Attended
 */

// @lc code=start
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        int res = 0;
        for (int d = 1, i = 0; d <= 100000; d++) {
            while (!pq.empty() && pq.top() < d) pq.pop();
            while (i < events.size() && events[i][0] <= d) pq.push(events[i++][1]);
            if (!pq.empty()) {
                res++;
                pq.pop();
            }
        }
        return res;
    }
};
// @lc code=end

