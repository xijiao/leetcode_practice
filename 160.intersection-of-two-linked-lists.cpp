/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = countList(headA), countB = countList(headB);
        ListNode *curA = headA, *curB = headB;
        for (int i = 0; i < countA - countB; i++) curA = curA->next;
        for (int i = 0; i < countB - countA; i++) curB = curB->next;
        for (; curA || curB;) {
            if (curA == curB) return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }

    int countList(ListNode *head) {
        int res = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            res++;
        }
        return res;
    }
};
// @lc code=end

