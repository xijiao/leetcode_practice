/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *cur = root;
        for (; cur;) {
            Node *cur2l = nullptr, *head = nullptr;
            for (; cur; cur = cur->next) {
                if (cur->left) {
                    if (!cur2l) {
                        head = cur2l = cur->left;
                    } else {
                        cur2l->next = cur->left;
                        cur2l = cur->left;
                    }
                }
                if (cur->right) {
                    if (!cur2l) {
                        head = cur2l = cur->right;
                    } else {
                        cur2l->next = cur->right;
                        cur2l = cur->right;
                    }
                }
            }
            cur = head;
        }
        return root;
    }
};
// @lc code=end

