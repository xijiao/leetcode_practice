/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    queue<TreeNode*> Q;
    Q.push(root);
    int ans = 0;
    while (!Q.empty()) {
      ++ans;
      for (int i = Q.size(); i > 0; --i) {
        TreeNode* cur = Q.front();
        Q.pop();
        if (cur->left) Q.push(cur->left);
        if (cur->right) Q.push(cur->right);
      }
    }
    return ans;
  }
};
// @lc code=end
