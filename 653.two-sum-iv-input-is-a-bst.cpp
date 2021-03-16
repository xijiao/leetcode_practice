/*
 * @lc app=leetcode id=653 lang=cpp
 *
 * [653] Two Sum IV - Input is a BST
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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> S;
        return dfs(root, k, S);
    }

    bool dfs(TreeNode* root, int k, unordered_set<int>& S) {
        if (!root) return false;
        if (S.count(k - root->val)) return true;
        S.insert(root->val);
        return dfs(root->left, k, S) || dfs(root->right, k, S);
    }
};
// @lc code=end

