/*
 * @lc app=leetcode id=971 lang=cpp
 *
 * [971] Flip Binary Tree To Match Preorder Traversal
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        if (helper(root, voyage, 0, res) == -1) return {-1};
        return res;
    }

    int helper(TreeNode* root, vector<int>& voyage, int index, vector<int>& res) {
        if (!root) return index;
        if (root->val != voyage[index]) return -1;
        if (root->left && root->right && root->right->val == voyage[index + 1]) {
            res.push_back(root->val);
            swap(root->left, root->right);
        }
        if (root->left) index = helper(root->left, voyage, index + 1, res);
        if (index == -1) return -1;
        if (root->right) index = helper(root->right, voyage, index + 1, res);
        return index;
    }
};
// @lc code=end

