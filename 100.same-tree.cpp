/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    queue<TreeNode*> Q1, Q2;
    Q1.push(p);
    Q2.push(q);
    while (!Q1.empty()) {
      TreeNode* cur1 = Q1.front();
      Q1.pop();
      TreeNode* cur2 = Q2.front();
      Q2.pop();
      if (!!cur1 != !!cur2) return false;
      if (!cur1) continue;
      if (cur1->val != cur2->val) return false;
      Q1.push(cur1->left);
      Q2.push(cur2->left);
      Q1.push(cur1->right);
      Q2.push(cur2->right);
    }
    return true;
  }
};
// @lc code=end
