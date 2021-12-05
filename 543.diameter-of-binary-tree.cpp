/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
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
  int ans = 0;

 public:
  int diameterOfBinaryTree(TreeNode* root) {
    traverse(root);
    return ans;
  }

  int traverse(TreeNode* node) {
    if (!node) return 0;
    int l = traverse(node->left), r = traverse(node->right);
    ans = max(ans, l + r);
    return max(l, r) + 1;
  }
};
// @lc code=end
