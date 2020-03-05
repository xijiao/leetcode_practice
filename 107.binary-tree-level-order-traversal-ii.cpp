/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        dfs(res, root, 0);
        for (int i = 0; i < res.size() / 2; i++) {
            swap(res[i], res[res.size() - i - 1]);
        }
        return res;
    }

    void dfs(vector<vector<int>>& res, TreeNode* node, int level) {
        if (res.size() < level + 1) {
            res.push_back(vector<int>());
        }
        res[level].push_back(node->val);
        if (node->left) dfs(res, node->left, level + 1);
        if (node->right) dfs(res, node->right, level + 1);
    }
};
// @lc code=end

