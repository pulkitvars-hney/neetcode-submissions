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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* first=list1;
        ListNode* second=list2;
        ListNode* dummy=new ListNode();
        ListNode* head=dummy;
        while(first!=nullptr && second!=nullptr){
            if(first->val<second->val){
                head->next=first;
                head=first;
                first=first->next;
            }else{
                head->next=second;
                head=second;
                second=second->next;
            }
        }
        while(first){
            head->next=first;
            first=first->next;
            head=head->next;
        }
        while(second){
            head->next=second;
            head=head->next;
            second=second->next;
        }
        return dummy->next;
    }
};
