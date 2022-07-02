/*
 * @lc app=leetcode id=998 lang=cpp
 *
 * [998] Maximum Binary Tree II
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root != nullptr && root->val > val) {
      root->right = insertIntoMaxTree(root->right, val);
      return root;
    } else {
      TreeNode* newRoot = new TreeNode(val);
      newRoot->left = root;
      return newRoot;
    }
  }
};
// @lc code=end
