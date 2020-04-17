/*
 * @lc app=leetcode id=1339 lang=cpp
 *
 * [1339] Maximum Product of Splitted Binary Tree
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
    int maxProduct(TreeNode* root) {
        calcSum(root);
        return findMaxProduct(root->val, root) % 1000000007L;
    }

    void calcSum(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            calcSum(root->left);
            root->val += root->left->val;
        }
        if (root->right) {
            calcSum(root->right);
            root->val += root->right->val;
        }
    }

    long long findMaxProduct(int total, TreeNode* root) {
        if (!root) return 0;
        return max(((long long)total - root->val) * root->val,
            max(findMaxProduct(total, root->left), findMaxProduct(total, root->right)));
    }
};
// @lc code=end

