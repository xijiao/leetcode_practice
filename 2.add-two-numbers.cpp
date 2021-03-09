/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* cur = nullptr;
        int adv = 0;
        for (; l1 || l2;) {
            int v = adv;
            if (l1) v += l1->val;
            if (l2) v += l2->val;
            ListNode* node = new ListNode{v % 10, nullptr};
            if (!cur) {
                cur = head = node;
            } else {
                cur->next = node;
                cur = node;
            }
            adv = v / 10;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (adv || cur == nullptr) {
            ListNode* node = new ListNode{adv, nullptr};
            if (!cur) {
                cur = head = node;
            } else {
                cur->next = node;
                cur = node;
            }

        }
        return head;
    }
};
// @lc code=end

