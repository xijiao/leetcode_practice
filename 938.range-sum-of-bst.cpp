/*
 * @lc app=leetcode id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
  int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return false;
    if (root->val >= low && root->val <= high) {
      return root->val + rangeSumBST(root->left, low, high) +
             rangeSumBST(root->right, low, high);
    } else if (root->val > high) {
      return rangeSumBST(root->left, low, high);
    } else {
      return rangeSumBST(root->right, low, high);
    }
  }
};
// @lc code=end
