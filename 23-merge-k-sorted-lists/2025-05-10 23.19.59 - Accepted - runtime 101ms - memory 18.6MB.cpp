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
    ListNode* merge(ListNode* h1, ListNode* h2){
        ListNode *dummy=new ListNode(-1);
        ListNode *last=dummy;
        while(h1 && h2){
            if(h1->val < h2->val){
                last->next=h1;
                last=h1;
                h1=h1->next;
            }
            else{
                last->next=h2;
                last=h2;
                h2=h2->next;
            }
        }
        if(h1){
            last->next=h1;
        }
        else if(h2){
            last->next=h2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1) return lists[0];
        else if(lists.size()==0) return nullptr;
        ListNode* head = merge(lists[0], lists[1]);
        int i=2;
        while(i<lists.size()){
            if(lists[i]==nullptr) continue;
            else{
                head=merge(lists[i], head);
            }
                i++;
        }
        return head;
    }
};
