/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }

    void dfs(const vector<int>& nums, vector<vector<int>>& res, vector<int>& cur,
            int start) {
        res.push_back(cur);
        for (int i = start; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            dfs(nums, res, cur, i + 1);
            cur.pop_back();
        }
    }
};
// @lc code=end

