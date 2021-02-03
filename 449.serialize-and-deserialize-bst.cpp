/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(ss, root);
        return ss.str();
    }

    void serialize(stringstream& ss, TreeNode* root) {
        if (!root) {
            ss << "#";
            return;
        }
        ss << root->val << ",";
        serialize(ss, root->left);
        serialize(ss, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize(ss);
    }

    TreeNode* deserialize(stringstream& ss) {
        if (ss.peek() == '#') {
            ss.get();
            return nullptr;
        }
        TreeNode* node = new TreeNode();
        ss >> node->val;
        ss.get();
        node->left = deserialize(ss);
        node->right = deserialize(ss);
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

