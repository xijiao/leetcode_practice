/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 */

// @lc code=start
class Solution {
public:
/*
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int, greater<int>> diff2maxp;
        int n = difficulty.size();
        for (int i = 0; i < n; i++) {
            int d = difficulty[i];
            int p = profit[i];
            diff2maxp[d] = max(diff2maxp[d], p);
        }

        int curMaxProfit = 0;
        for (auto it = diff2maxp.rbegin(); it != diff2maxp.rend();) {
            if (it->second > curMaxProfit) {
                curMaxProfit = it->second;
                ++it;
            } else {
                it = reverse_iterator(diff2maxp.erase(next(it,1).base()));
            }
        }
        for (const auto& d2m : diff2maxp) {
            cout << d2m.first << ":" << d2m.second << ",";
        }
        cout << endl;

        int res = 0;
        for (int w : worker) {
            auto it = diff2maxp.lower_bound(w);
            if (it != diff2maxp.end()) {
                res += it->second;
            }
        }
        return res;
    }
*/
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        int N = difficulty.size();
        for (int i = 0; i < N; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int res = 0, best = 0, k = 0;
        for (int ability : worker) {
            for (; k < N && ability >= jobs[k].first; k++) {
                best = max(best, jobs[k].second);
            }
            //cout << ability << ":" << best;
            res += best;
        }
        return res;
    }
};
// @lc code=end

