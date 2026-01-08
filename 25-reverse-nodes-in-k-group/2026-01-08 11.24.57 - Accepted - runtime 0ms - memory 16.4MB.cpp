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
class Solution{
public:
    bool check(ListNode *r,int k){
        while(k){
            if(!r) return false;
            r=r->next;
            k--;
        }
        return true;
    }
    ListNode *reverse(ListNode *r,int k){
        ListNode *head=nullptr;
        ListNode *curr=r;
        ListNode* last=r->next;
        while(k){
            curr->next=head;
            head=curr;
            curr=last;
            if(last) last=last->next;
            k--;
        }
        r->next=curr;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k){
        
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        ListNode *root=dummy;
        while(check(head,k)){
            dummy->next=reverse(head,k);
            int k_=k;
            while(k_--){
                dummy=dummy->next;
            }
            head=dummy->next;
        }
        return root->next;
    }
};
