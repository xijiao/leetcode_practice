/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newHead = nullptr, *newCur = nullptr;
        for (ListNode* cur = head; cur; cur = cur->next) {
            if (cur->val == val) continue;
            if (!newCur) {
                newHead = newCur = cur;
            } else {
                newCur->next = cur;
                newCur = cur;
            }
        }
        if (!newCur) return nullptr;
        newCur->next = nullptr;
        return newHead;
    }
};
// @lc code=end

