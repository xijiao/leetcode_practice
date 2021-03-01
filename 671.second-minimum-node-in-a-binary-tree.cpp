/*
 * @lc app=leetcode id=671 lang=cpp
 *
 * [671] Second Minimum Node In a Binary Tree
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
    // int findSecondMinimumValue(TreeNode* root, int minValue = -1) {
    //     if (minValue == -1) minValue = root->val;
    //     if (root->val != minValue) return root->val;
    //     if (!root->left) return -1;

    //     int l = findSecondMinimumValue(root->left, minValue);
    //     int r = findSecondMinimumValue(root->right, minValue);
    //     if (l == -1 && r == -1) return -1;
    //     else if (l == -1) return r;
    //     else if (r == -1) return l;
    //     else return min(l, r);
    // }

    int findSecondMinimumValue(TreeNode* root) {
        int minValue = root->val;
        int res = -1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (res != -1 && cur->val >= res) continue;
            if (cur->val != minValue) {
                if (res == -1) res = cur->val;
                else res = min(res, cur->val);
            }
            if (cur->left) {
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return res;
    }
};
// @lc code=end

