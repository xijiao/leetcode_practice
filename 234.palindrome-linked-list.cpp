/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
  bool isPalindrome(ListNode* head) {
    int n = count(head);
    if (n < 2) return true;
    ListNode* mid = forward(head, n / 2 - 1);
    if (n % 2) {
      ListNode* next = mid->next;
      mid->next = nullptr;
      mid = next;
    }
    ListNode* right = reverse(mid->next);
    mid->next = nullptr;
    return isSame(head, right);
  }

  int count(ListNode* head) {
    int res = 0;
    while (head) {
      ++res;
      head = head->next;
    }
    return res;
  }

  ListNode* forward(ListNode* head, int k) {
    for (int i = 0; i < k; ++i) {
      head = head->next;
    }
    return head;
  }

  ListNode* reverse(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = nullptr;
    for (; head;) {
      ListNode* next = head->next;
      head->next = newHead;
      newHead = head;
      head = next;
    }
    return newHead;
  }

  bool isSame(ListNode* left, ListNode* right) {
    for (; left && right; left = left->next, right = right->next) {
      if (left->val != right->val) return false;
    }
    return !left && !right;
  }
};
// @lc code=end
