/*
 * @lc app=leetcode id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root, TreeNode* maxNode = nullptr) {
        if (!root) return 0;
        int res = 0;
        if (!maxNode || maxNode->val <= root->val) {
            maxNode = root;
            res++;
        }
        res += goodNodes(root->left, maxNode);
        res += goodNodes(root->right, maxNode);
        return res;
    }
};
// @lc code=end

