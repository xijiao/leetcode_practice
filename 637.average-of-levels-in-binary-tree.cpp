/*
 * @lc app=leetcode id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
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
  vector<double> averageOfLevels(TreeNode* root) {
    vector<double> ans;
    queue<TreeNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
      int count = Q.size();
      double sum = 0;
      for (int i = 0; i < count; i++) {
        TreeNode* cur = Q.front();
        Q.pop();
        sum += cur->val;
        if (cur->left) Q.push(cur->left);
        if (cur->right) Q.push(cur->right);
      }
      ans.push_back(sum / count);
    }
    return ans;
  }
};
// @lc code=end
