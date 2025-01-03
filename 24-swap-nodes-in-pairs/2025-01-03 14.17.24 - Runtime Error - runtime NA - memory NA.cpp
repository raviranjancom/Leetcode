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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *front=head->next, *back=NULL;
        while(front!=NULL){
            if(back==NULL){
                back=head;
                ListNode* temp=front->next;
                front->next=back;
                back->next=temp;
                head=front;
                front=temp;
            }
            else{
                if(front->next!=NULL) ;
                front=front->next;
                ListNode* temp=front->next;
                front->next=back->next;
                back->next->next=temp;
                back->next=front;
                back=front->next;
                front=temp;
            }
        }
        return head;
    }
};
