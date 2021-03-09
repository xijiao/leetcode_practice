/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
    int prev = 0;
    int count = 0;
    int maxcount = 0;
    vector<int> res;
public:
    vector<int> findMode(TreeNode* root) {
        traverse(root);
        return res;
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        if (root->left) traverse(root->left);
        if (prev != root->val || count == 0) {
            prev = root->val;
            count = 0;
        }
        count++;
        if (count > maxcount) {
            res = {root->val};
            maxcount = count;
        } else if (count == maxcount) {
            res.push_back(root->val);
        }
        if (root->right) traverse(root->right);
    }
};
// @lc code=end

