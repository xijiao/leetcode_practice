/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
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
  vector<int> postorder(Node* root) {
    if (!root) return {};
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
      Node* cur = st.top();
      st.pop();
      ans.push_back(cur->val);
      for (int i = 0; i < cur->children.size(); ++i) {
        st.push(cur->children[i]);
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
