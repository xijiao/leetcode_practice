/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int l, int r) {
        if (l > r) return {nullptr};
        if (l == r) return {new TreeNode(l)};
        vector<TreeNode*> result;
        for (int i = l; i <= r; i++) {
            vector<TreeNode*> lresults = generateTrees(l, i - 1);
            vector<TreeNode*> rresults = generateTrees(i + 1, r);
            for (auto lresult : lresults) {
                for (auto rresult : rresults) {
                    result.push_back(new TreeNode(i, lresult, rresult));
                }
            }
        }
        return result;
    }
};
// @lc code=end

