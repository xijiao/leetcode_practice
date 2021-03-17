/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
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
    int res = 0;
    struct Info {
        bool bst;
        bool empty;
        int lower;
        int upper;
        int sum;
    };
public:
    int maxSumBST(TreeNode* root) {
        find(root);
        return res;
    }
    
    Info find(TreeNode* root) {
        if (!root) return {true, true, 0, 0, 0};
        Info l = find(root->left);
        Info r = find(root->right);
        if (!l.bst || !r.bst) return {false, false, 0, 0, 0};
        if (!l.empty && l.upper >= root->val) return {false, false, 0, 0, 0};
        if (!r.empty && r.lower <= root->val) return {false, false, 0, 0, 0};

        Info info{true, false, root->val, root->val, root->val};
        if (!l.empty) {
            info.lower = min(info.lower, l.lower);
            info.sum += l.sum;
        }
        if (!r.empty) {
            info.upper = max(info.upper, r.upper);
            info.sum += r.sum;
        }
        res = max(res, info.sum);
        return info;
    }
};
// @lc code=end

