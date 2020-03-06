/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(nums.size(), false);
        dfs(nums, res, cur, used);
        return res;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& cur,
            vector<bool>& used) {
        
        int hasLeft = false;
        for (int i = 0; i < nums.size();) {
            if (used[i]) {
                i++;
                continue;
            }
            hasLeft = true;
            int v = nums[i];
            cur.push_back(v);
            used[i] = true;
            dfs(nums, res, cur, used);
            used[i] = false;
            cur.pop_back();
            while (i < nums.size() && nums[i] == v) i++;
        }
        if (!hasLeft) {
            res.push_back(cur);
        }
    }
};
// @lc code=end

