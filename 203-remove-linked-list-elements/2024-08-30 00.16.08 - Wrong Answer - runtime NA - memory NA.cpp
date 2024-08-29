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
        ListNode *p=NULL,*t=NULL;
        if(head==NULL) return head;
        if(head->val==val && head->next==NULL){
            head=head->next;
            return head;
        }
        t=head;
        p=head;
        if(p->next) p=p->next;
        if(t->val==val){
            head=head->next;
        }
        while(p){
            if(p->val==val){
                t->next=p->next;
                p->next=NULL;
                p=t->next;
            }
            else{
                p=p->next;
                t=t->next;
            }
        }
        ListNode *b=head;
        if(b->val==val){
            head=NULL;
            return head;
        }
        return head;
    }
};