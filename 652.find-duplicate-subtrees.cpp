/*
 * @lc app=leetcode id=652 lang=cpp
 *
 * [652] Find Duplicate Subtrees
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> cache;
        traverse(root, cache);
        vector<TreeNode*> res;
        for (const auto& c : cache) {
            if (c.second.size() > 1) {
                res.push_back(c.second[0]);
            }
        }
        return res;
    }

    string traverse(TreeNode* root, unordered_map<string, vector<TreeNode*>>& cache) {
        stringstream ss;
        ss << root->val << ",";
        if (root->left) ss << traverse(root->left, cache);
        else ss << '#';
        if (root->right) ss << traverse(root->right, cache);
        else ss << '#';
        string res = ss.str();
        cache[res].push_back(root);
        return res;
    }
};
// @lc code=end

