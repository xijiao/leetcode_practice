/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
    unordered_map<int, int> count;
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        int maxcount = -1;
        for (auto& kv : count) {
            maxcount = max(maxcount, kv.second);
        }
        vector<int> res;
        for (auto& kv : count) {
            if (kv.second == maxcount) res.push_back(kv.first);
        }
        return res;
    }

    int helper(TreeNode* root) {
        if (!root) return 0;
        int res = root->val;
        res += helper(root->left);
        res += helper(root->right);
        count[res]++;
        return res;
    }
};
// @lc code=end

