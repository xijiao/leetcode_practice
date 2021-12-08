/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  vector<int> preorder(Node* root) {
    if (!root) return {};
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
      Node* cur = st.top();
      st.pop();
      ans.push_back(cur->val);
      for (int i = cur->children.size() - 1; i >= 0; --i) {
        st.push(cur->children[i]);
      }
    }
    return ans;
  }
};
// @lc code=end
