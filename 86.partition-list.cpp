/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* ahead = nullptr, *bhead = nullptr;
        ListNode** atail = &ahead, **btail = &bhead;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val < x) {
                append2Tail(atail, cur);
            } else {
                append2Tail(btail, cur);
            }
        }
        append2Tail(atail, bhead);
        append2Tail(btail, nullptr);
        return ahead;
    }

    void append2Tail(ListNode**& tail, ListNode* node) {
        *tail = node;
        if (node) tail = &(node->next);
    }
};
// @lc code=end

