/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* former = head;
        ListNode* cur = former->next;
        while (cur) {
            if (cur->val != former->val) {
                former->next = cur;
                former = cur;
            }
            cur = cur->next;
        }
        former->next = nullptr;
        return head;
    }
};
// @lc code=end

