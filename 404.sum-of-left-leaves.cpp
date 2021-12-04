/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
  int sumOfLeftLeaves(TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    if (isLeaf(root->left)) {
      ans += root->left->val;
    } else {
      ans += sumOfLeftLeaves(root->left);
    }
    ans += sumOfLeftLeaves(root->right);
    return ans;
  }

  bool isLeaf(TreeNode* node) { return node && !node->left && !node->right; }
};
// @lc code=end
