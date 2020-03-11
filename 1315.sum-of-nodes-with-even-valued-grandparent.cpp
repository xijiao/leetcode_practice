/*
 * @lc app=leetcode id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
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
    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, false);
    }

    int dfs(TreeNode* node, bool parentIsEven) {
        if (!node) return 0;
        int res = 0;
        if (parentIsEven) {
            if (node->left) res += node->left->val;
            if (node->right) res += node->right->val;
        }
        res += dfs(node->left, node->val % 2 == 0);
        res += dfs(node->right, node->val % 2 == 0);
        return res;
    }
};
// @lc code=end

