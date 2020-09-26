/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        ListNode* former = &dummy;
        ListNode* cur = head;
        while (cur) {
            if (!cur->next || cur->val != cur->next->val) {
                former->next = cur;
                former = former->next;
                cur = cur->next;
            } else {
                int v = cur->val;
                while (cur && cur->val == v) {
                    cur = cur->next;
                }
            }
        }
        former->next = nullptr;
        return dummy.next;
    }
};
// @lc code=end

