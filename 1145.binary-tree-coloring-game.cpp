/*
 * @lc app=leetcode id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        if (x == root->val) return countTree(root->left) > n / 2 || countTree(root->right) > n / 2;
        auto xNode = findInTree(root, x);
        int countLeft = countTree(xNode->left), countRight = countTree(xNode->right);
        return (countLeft > n / 2 || countRight > n / 2 || (n - countLeft - countRight - 1) > n /2);
    }

    TreeNode* findInTree(TreeNode* root, int x) {
        if (!root) return nullptr;
        if (root->val == x) return root;
        auto res = findInTree(root->left, x);
        if (res) return res;
        res = findInTree(root->right, x);
        return res;
    }

    int countTree(TreeNode* root) {
        if (!root) return 0;
        int res = 1;
        res += countTree(root->left);
        res += countTree(root->right);
        return res;
    }
};
// @lc code=end

