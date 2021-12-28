/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
  // bool leafSimilar(TreeNode* root1, TreeNode* root2) {
  //   vector<int> res1, res2;
  //   getLeaves(root1, res1);
  //   getLeaves(root2, res2);
  //   return res1 == res2;
  // }

  // void getLeaves(TreeNode* node, vector<int>& res) {
  //   if (!node) return;
  //   if (!node->left && !node->right) {
  //     res.push_back(node->val);
  //     return;
  //   }
  //   getLeaves(node->left, res);
  //   getLeaves(node->right, res);
  // }
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1, s2;
    s1.push(root1);
    s2.push(root2);
    while (!s1.empty() || !s2.empty()) {
      if (dfs(s1) != dfs(s2)) return false;
    }
    return true;
  }

  int dfs(stack<TreeNode*>& st) {
    while (!st.empty()) {
      TreeNode* cur = st.top();
      st.pop();
      if (cur->right) st.push(cur->right);
      if (cur->left) st.push(cur->left);
      if (!cur->left && !cur->right) return cur->val;
    }
    return -1;
  }
};
// @lc code=end
