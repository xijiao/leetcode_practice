/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* cur = head; cur; cur = cur->next) {
            if (!cur->child) continue;
            Node* next = cur->next;
            Node* child = cur->child;
            cur->next = child;
            child->prev = cur;
            for (; child->next; child = child->next);
            child->next = next;
            if (next) next->prev = child;
            cur->child = nullptr;
        } 
        return head;
    }
};
// @lc code=end

