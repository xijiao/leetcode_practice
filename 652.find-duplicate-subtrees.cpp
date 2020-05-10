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
        findAndInsertCache(cache, root);
        vector<TreeNode*> res;
        for (const auto& p : cache) {
            if (p.second.size() > 1) res.push_back(p.second[0]);
        }
        return res;
    }

    string findAndInsertCache(unordered_map<string, vector<TreeNode*>>& cache, TreeNode* cur) {
        if (!cur) return "N";
        stringstream ss;
        ss << "(";
        ss << findAndInsertCache(cache, cur->left);
        ss << to_string(cur->val);
        ss << findAndInsertCache(cache, cur->right);
        ss << ")";
        cache[ss.str()].push_back(cur);
        return ss.str();
    }
};
// @lc code=end

