/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(nums, res, cur, 0);
        return res;
    }

    void dfs(const vector<int>& nums, vector<vector<int>>& res, vector<int>& cur,
            int start) {
        res.push_back(cur);
        for (int i = start; i < nums.size();) {
            int v = nums[i];
            cur.push_back(v);
            dfs(nums, res, cur, i + 1);
            cur.pop_back();
            while (i < nums.size() && nums[i] == v) i++;
        }
    }
};
// @lc code=end

