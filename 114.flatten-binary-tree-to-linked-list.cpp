/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        for (TreeNode* cur = root; cur;) {
            if (!cur->left) {
                cur = cur->right;
                continue;
            }
            TreeNode* left = cur->left;
            TreeNode* right = cur->right;
            cur->right = left;
            cur->left = nullptr;
            while (left->right) left = left->right;
            left->right = right;
            cur = cur->right;
        }
    }
};
// @lc code=end

