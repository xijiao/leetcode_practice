/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        dfs(res, cur, n, 0, 0);
        return res;
    }

    void dfs(vector<string>& res, string& cur,
            int n, int l, int r) {
        if (l == n && r == n) {
            res.push_back(cur);
            return;
        }
        if (l < n) {
            cur.push_back('(');
            dfs(res, cur, n, l + 1, r);
            cur.pop_back();
        }
        if (l > r) {
            cur.push_back(')');
            dfs(res, cur, n, l, r + 1);
            cur.pop_back();
        }
    }
};
// @lc code=end

