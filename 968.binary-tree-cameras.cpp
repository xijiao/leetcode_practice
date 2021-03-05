/*
 * @lc app=leetcode id=968 lang=cpp
 *
 * [968] Binary Tree Cameras
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
    enum {
        kPutCamera = 0,
        kNeedCover,
        kCovered
    };
    int res = 0;

    int minCameraCover(TreeNode* root) {
        return (dfs(root) == kNeedCover ? 1 : 0) + res;
    }

    int dfs(TreeNode* root) {
        if (!root) return kCovered;

        int l = dfs(root->left), r = dfs(root->right);
        if (l == kNeedCover || r == kNeedCover) {
            res++;
            return kPutCamera;
        }
        if (l == kPutCamera || r == kPutCamera) {
            return kCovered;
        } else {
            return kNeedCover;
        }
    }

    /* Brutal, slow
    int minCameraCover(TreeNode* root) {
        unordered_map<uint64_t, int> dp;
        return minCameraCoverDP(root, false, false, dp);
    }

    int minCameraCoverDP(TreeNode* root, bool parentNeedCovered,  bool parentHasCamera, unordered_map<uint64_t, int>& dp) {
        if (!root) return 0;
        uint64_t key(reinterpret_cast<uint64_t>(root) | ((parentNeedCovered ? 2ULL : 0ULL) + (parentHasCamera ? 1ULL : 0ULL)) << 61ULL);
        if (dp.count(key)) return dp[key];
        int res = minCameraCoverDP(root->left, false, true, dp) + minCameraCoverDP(root->right, false, true, dp) + 1;
        if (parentHasCamera) {
            res = min(res, minCameraCoverDP(root->left, false, false, dp) + minCameraCoverDP(root->right, false, false, dp));
        }
        if (!parentNeedCovered) {
            if (root->left) res = min(res, minCameraCoverDP(root->left, true, false, dp) + minCameraCoverDP(root->right, false, false, dp));
            if (root->right) res = min(res, minCameraCoverDP(root->left, false, false, dp) + minCameraCoverDP(root->right, true, false, dp));
        }
        dp[key] = res;
        return res;
    }
    */
};
// @lc code=end

