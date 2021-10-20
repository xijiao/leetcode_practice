/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
class Solution
{
    unordered_map<int, int> inmap;
    unordered_map<int, int> postmap;

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++)
        {
            inmap[inorder[i]] = i;
            postmap[postorder[i]] = i;
        }
        return buildSubTree(inorder, 0, n - 1, postorder, 0, n - 1);
    }

    TreeNode *buildSubTree(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr)
    {
        //cout << il << " " << ir << " " << pl << " " << pr << endl;
        if (il > ir)
            return nullptr;
        if (il == ir)
            return new TreeNode(inorder[il]);
        int im = inmap[postorder[pr]];
        int leftcount = im - il;
        int rightcount = ir - im;
        return new TreeNode(inorder[im],
                            buildSubTree(inorder, il, im - 1, postorder, pl, pl + leftcount - 1),
                            buildSubTree(inorder, im + 1, ir, postorder, pr - rightcount, pr - 1));
    }
};
// @lc code=end
