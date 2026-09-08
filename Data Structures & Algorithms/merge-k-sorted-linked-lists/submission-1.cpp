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
    // ListNode* merge(ListNode* head1, ListNode* head2) {
    //     ListNode dummy;
    //     ListNode* temp = &dummy;

    //     while (head1 && head2) {
    //         if (head1->val < head2->val) {
    //             temp->next = head1;
    //             head1 = head1->next;
    //         } else {
    //             temp->next = head2;
    //             head2 = head2->next;
    //         }

    //         temp = temp->next;
    //     }

    //     if (head1) temp->next = head1;

    //     if (head2) temp->next = head2;

    //     return dummy.next;
    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

       priority_queue<
    pair<int, ListNode*>,
    vector<pair<int, ListNode*>>,
    greater<pair<int, ListNode*>>
> pq;


        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
        pq.push({lists[i]->val, lists[i]});
    }
        }
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        while(!pq.empty()){
            ListNode* node=pq.top().second;
            pq.pop();
            temp->next=node;
            temp=node;
            if(node->next) pq.push({node->next->val,node->next});
        }

        return dummy->next;
    }
};