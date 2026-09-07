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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* fast = dummy;

    // Move fast n+1 steps
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    ListNode* slow = dummy;

    // Move until fast reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // slow is now just before the node to remove
    ListNode* curr = slow->next;
    slow->next = curr->next;

    delete curr;

    head = dummy->next;
    delete dummy;

    return head;
    }
};
