/*
 * @lc app=leetcode id=993 lang=cpp
 *
 * [993] Cousins in Binary Tree
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root || root->val == x || root->val == y) return false;
        int parents[2] = {0};
        int levels[2] = {0};
        search(parents, levels, 1, root->val, root->left, x, y);
        search(parents, levels, 1, root->val, root->right, x, y);
        return (parents[0] != parents[1] && levels[0] == levels[1]);
    }

    void search(int* parents, int* levels, int level, int parent, TreeNode* node, int x, int y) {
        if (!node) return;
        if (node->val == x) {
            parents[0] = parent;
            levels[0] = level;
        }
        if (node->val == y) {
            parents[1] = parent;
            levels[1] = level;
        }
        if (parents[0] && parents[1]) return;
        search(parents, levels, level + 1, node->val, node->left, x, y);
        search(parents, levels, level + 1, node->val, node->right, x, y);
    }
};
// @lc code=end

