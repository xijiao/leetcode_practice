/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> preq;
        unordered_map<int, int> needed;
        queue<int> q;
        for (const auto& p : prerequisites) {
            preq[p[1]].push_back(p[0]);
            needed[p[0]]++;
        }
        for (int i = 0; i < numCourses; i++) {
            if (needed[i] == 0) {
                res.push_back(i);
                q.push(i);
            }
        }
        for (; !q.empty();) {
            int cur = q.front();
            q.pop();

            for (int t : preq[cur]) {
                needed[t]--;
                if (needed[t] == 0) {
                    res.push_back(t);
                    q.push(t);
                }
            }
        }
        if (res.size() == numCourses) return res;
        else return {};
    }
};
// @lc code=end

