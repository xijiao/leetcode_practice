/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* t = st.top(); st.pop();
            res.push_back(t->val);
            if (t->left) st.push(t->left);
            if (t->right) st.push(t->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

