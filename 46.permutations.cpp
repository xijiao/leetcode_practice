/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        dfs(nums, res, cur, used);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur,
            vector<bool>& used) {
        
        int hasLeft = false;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            hasLeft = true;
            cur.push_back(nums[i]);
            used[i] = true;
            dfs(nums, res, cur, used);
            used[i] = false;
            cur.pop_back();
        }
        if (!hasLeft) {
            res.push_back(cur);
        }
    }
};
// @lc code=end

