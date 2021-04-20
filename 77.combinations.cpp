/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> cur;
        helper(n, k, cur, 1);
        return res;
    }

    void helper(int n, int k, vector<int>& cur, int index) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }

        for (int i = index; i <= n; i++) {
            cur.push_back(i);
            helper(n, k, cur, i + 1);
            cur.pop_back();
        }
    }
};
// @lc code=end

