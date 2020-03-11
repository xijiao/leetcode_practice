/*
 * @lc app=leetcode id=1235 lang=cpp
 *
 * [1235] Maximum Profit in Job Scheduling
 */

// @lc code=start
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> start2profit;
        struct Job {
            //int start;
            int end;
            int profit;
            Job(int e, int p) : end(e), profit(p) {}
        };
        unordered_map<int, vector<Job>> jobs;
        int n = startTime.size();
        for (int i = 0; i < n; i++) {
            start2profit[startTime[i]] = 0;
            jobs[startTime[i]].emplace_back(endTime[i], profit[i]);
        }
        int maxprofit = 0;
        for (auto it = start2profit.rbegin(); it != start2profit.rend(); ++it) {
            for (auto& job : jobs[it->first]) {
                auto it2 = start2profit.lower_bound(job.end);
                maxprofit = max(maxprofit, job.profit + (it2 == start2profit.end() ? 0 : it2->second));
            }
            it->second = maxprofit;
        }
        return maxprofit;
    }
};
// @lc code=end

