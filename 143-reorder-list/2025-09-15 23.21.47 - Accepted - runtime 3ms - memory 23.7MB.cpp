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
    int traverse(ListNode *r){
        int count=0;
        while(r && r->next){
            r=r->next->next;
            if(r) count++;
        }
        return count;
    }
    void fillstack(ListNode *r, stack<ListNode *> &st){
        while(r){
            st.push(r);
            r=r->next;
        }
    }
    void reorderList(ListNode* head) {
        ListNode *fast=head,*slow=head;
        int count=traverse(head);
        stack<ListNode *> st;
        fillstack(head,st);
        ListNode *node=head, *last=head;
        node=node->next;
        while(count-- && node){
            ListNode *x=st.top(); st.pop();
            last->next=x;
            x->next=node;

            last=node;
            node=node->next;
        }
        if(st.top()==last){
            last->next=nullptr;
        }
        else{
            node->next=nullptr;
        } 
    }
};
