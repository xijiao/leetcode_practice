/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> AncestorP, AncestorQ;
        findAllAncestor(root, p, AncestorP);
        findAllAncestor(root, q, AncestorQ);
        TreeNode* preCommonA = nullptr;
        for (int i = 0; i < AncestorP.size() && i < AncestorQ.size(); i++) {
            if (AncestorP[i] != AncestorQ[i]) return preCommonA;
            preCommonA = AncestorP[i];
        }
        return preCommonA;
    }

    bool findAllAncestor(TreeNode* root, TreeNode* node, vector<TreeNode*>& AncestorP) {
        //cout << root->val << " ";
        AncestorP.push_back(root);
        if (root == node) return true;
        if (root->left && findAllAncestor(root->left, node, AncestorP)) return true;
        if (root->right && findAllAncestor(root->right, node, AncestorP)) return true;
        AncestorP.pop_back();
        return false;
    }

};
// @lc code=end

