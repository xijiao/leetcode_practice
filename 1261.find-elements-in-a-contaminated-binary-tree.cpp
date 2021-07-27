/*
 * @lc app=leetcode id=1261 lang=cpp
 *
 * [1261] Find Elements in a Contaminated Binary Tree
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
class FindElements {
    unordered_set<int> allValues;
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        helper(root);
    }
    
    bool find(int target) {
        return allValues.count(target) > 0;
    }

private:
    void helper(TreeNode* node) {
        allValues.insert(node->val);
        if (node->left) {
            node->left->val = node->val * 2 + 1;
            helper(node->left);
        }
        if (node->right) {
            node->right->val = node->val * 2 + 2;
            helper(node->right);
        }
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

