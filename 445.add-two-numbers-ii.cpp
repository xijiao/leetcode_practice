/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        stack<int> s1, s2;
        ListNode* head = nullptr;
        for (; l1; l1 = l1->next) s1.push(l1->val);
        for (; l2; l2 = l2->next) s2.push(l2->val);
        while (!s1.empty() || !s2.empty()) {
            int a = 0, b = 0;
            if (!s1.empty()) {
                a = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                b = s2.top();
                s2.pop();
            }
            int c = a + b + carry;
            carry = c / 10;
            c %= 10;
            ListNode* node = new ListNode(c, head);
            head = node;
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry, head);
            head = node;
        }
        return head;
    }
};
// @lc code=end

