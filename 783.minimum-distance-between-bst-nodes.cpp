/*
 * @lc app=leetcode id=783 lang=cpp
 *
 * [783] Minimum Distance Between BST Nodes
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
  TreeNode* pre = nullptr;
  int ans = INT_MAX;
public:
  int minDiffInBST(TreeNode* root) {
      inorder(root);
      return ans;
  }

  void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    if (pre && node->val - pre->val < ans) {
      ans = node->val - pre->val;
    }
    pre = node;
    inorder(node->right);
  }
};
// @lc code=end

