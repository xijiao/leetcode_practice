/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (l1 || l2) {
            if (!l1 || (l1 && l2 && l1->val > l2->val)) {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            } else {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }
        }
        cur->next= nullptr;
        return dummy.next;
    }
};
// @lc code=end

