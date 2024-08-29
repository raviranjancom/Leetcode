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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode *p=NULL,*t=head,*last=head;
        last->next?last=last->next:NULL;
        while(last!=NULL){
            t->next=p;
            p=t;
            t=last;
            last=last->next;
        }
        t->next=p;
        return t;
    }
};