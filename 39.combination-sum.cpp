/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(candidates, target, res, cur, 0, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& res,
            vector<int>& cur, int sum, int start) {
        if (sum == target) {
            res.push_back(cur);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            int c = candidates[i];
            if (c + sum > target) break;
            else {
                cur.push_back(c);
                dfs(candidates, target, res, cur, sum + c, i);
                cur.pop_back();
            }
        }
    }
};
// @lc code=end

