/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> cache;
        for (const vector<int>& p : prerequisites) {
            cache[p[0]].push_back(p[1]);
        }

        vector<bool> res;
        for (const vector<int>& q : queries) {
            queue<int> que;
            que.push(q[0]);
            bool found = false;
            while (!que.empty() && !found) {
                int v = que.front();
                que.pop();
                if (!cache.count(v)) continue;
                for (int k : cache[v]) {
                    if (k == q[1]) {
                        found = true;
                        break;
                    }
                    que.push(k);
                }
            }
            res.push_back(found);
        }
        return res;
    }
};
// @lc code=end

