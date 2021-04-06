/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    ListNode* middleNode(ListNode* head) {
        int n = countList(head);
        ListNode* cur = head;
        for (int i = 0; i < n / 2; i++) {
            cur = cur->next;
        }
        return cur;
    }

    int countList(ListNode* head) {
        int res = 0;
        for (auto cur = head; cur; cur = cur->next) {
            res++;
        }
        return res;
    }
};
// @lc code=end

