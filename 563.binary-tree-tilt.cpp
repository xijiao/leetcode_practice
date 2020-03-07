/*
 * @lc app=leetcode id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
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
    int findTilt(TreeNode* root) {
        auto titleNSum = findTiltNSum(root);
        return titleNSum.first;
    }

    pair<int, int> findTiltNSum(TreeNode* node) {
        if (!node) return {0, 0};
        auto l = findTiltNSum(node->left);
        auto r = findTiltNSum(node->right);
        return {l.first + r.first + abs(l.second - r.second),
                l.second + r.second + node->val};
    }
};
// @lc code=end

