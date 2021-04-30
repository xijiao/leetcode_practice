/*
 * @lc app=leetcode id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
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
    int maxAncestorDiff(TreeNode* root) {
        return helper(root, root->val, root->val);
    }

    int helper(TreeNode* cur, int lower, int upper) {
        if (!cur) return 0;
        int res = max(abs(lower - cur->val), abs(upper - cur->val));
        res = max(res, helper(cur->left, min(lower, cur->val), max(upper, cur->val)));
        res = max(res, helper(cur->right, min(lower, cur->val), max(upper, cur->val)));
        return res;
    }
};
// @lc code=end

