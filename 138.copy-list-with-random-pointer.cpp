/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newHead = nullptr, *cur = nullptr;
        unordered_map<Node*, Node*> M; // old -> new
        for (Node* n = head; n; n = n->next) {
            if (!cur) {
                newHead = cur = new Node{n->val, nullptr, n->random};
            } else {
                cur->next = new Node{n->val, nullptr, n->random};
                cur = cur->next;
            }
            M[n] = cur;
        }
        for (Node* n = newHead; n; n = n->next) {
            if (n->random) n->random = M[n->random];
        }

        return newHead;
    }
};
// @lc code=end

