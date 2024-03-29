/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
  bool isBalanced(TreeNode* root) { return helper(root).first; }

  pair<bool, int> helper(TreeNode* node) {
    if (!node) return {true, 0};
    if (!node->left && !node->right) return {true, 1};
    pair<bool, int> l = helper(node->left), r = helper(node->right);
    return {(l.first && r.first && abs(l.second - r.second) <= 1),
            max(l.second, r.second) + 1};
  }
};
// @lc code=end
