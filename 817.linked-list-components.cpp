/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> s(G.begin(), G.end());
        int res = 0;
        bool inset = false;
        for (; head; head = head->next) {
            if (s.find(head->val) != s.end()) {
                if (!inset) {
                    res++;
                    inset = true;
                }
            } else {
                inset = false;
            }
        }
        return res;
    }
};
// @lc code=end

