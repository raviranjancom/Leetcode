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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->val==0 && l2->val==0 && l1->next==NULL && l2->next==NULL) return l1;
        int i=0,x=0;
        while(l1){
            x+=l1->val*pow(10,i);
            i++;
            l1=l1->next;
        }
        int j=0,y=0;
        while(l2){
            y+=l2->val*pow(10,j);
            j++;
            l2=l2->next;
        }
        int ans=x+y;
        ListNode *r,*last,*t;
        int a=0,b=0,m=0;
        r=new ListNode;
        r->val=12;
        last=r;
        while(ans>0){
            t=new ListNode;
            b=ans%10;
            t->val=b;
            last->next=t;
            last=t;
            a=b*pow(10,m);
            ans=ans/10;
            m++;
        }
        r=r->next;
        return r;
    }
};
