/*
 * @lc app=leetcode id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
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
  int mindiff = INT_MAX;
  TreeNode* pre = nullptr;

 public:
  int getMinimumDifference(TreeNode* root) {
    inorder(root);
    return mindiff;
  }

  void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    if (pre) {
      mindiff = min(mindiff, node->val - pre->val);
    }
    pre = node;
    inorder(node->right);
  }
};
// @lc code=end
