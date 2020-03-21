/*
 * @lc app=leetcode id=725 lang=cpp
 *
 * [725] Split Linked List in Parts
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k, nullptr);
        int len = 0;
        for (auto node = root; node; node = node->next, len++);
        int n = len / k, r = len % k;
        
        auto node = root;
        for (int i = 0; node && i < k; i++) {
            res[i] = node;
            auto last = node;
            for (int j = 1; j < n + (i < r ? 1 : 0); j++) {
                last = last->next;
            }
            node = last->next;
            last->next = nullptr;
        }
        return res;
    }
};
// @lc code=end

