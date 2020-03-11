/*
 * @lc app=leetcode id=897 lang=cpp
 *
 * [897] Increasing Order Search Tree
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
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(0);
        TreeNode* cur = &dummy;
        increasingBST(root, cur);
        return dummy.right;
    }

    void increasingBST(TreeNode* node, TreeNode*& cur) {
        if (!node) return;
        TreeNode* right = node->right;
        increasingBST(node->left, cur);
        cur->right = node;
        node->left = nullptr;
        node->right = nullptr;
        cur = node;
        increasingBST(right, cur);
    }
};
// @lc code=end

