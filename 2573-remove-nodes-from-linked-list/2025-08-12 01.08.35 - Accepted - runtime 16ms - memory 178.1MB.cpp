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
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode *> st;
        ListNode *r=head;
        while(r){
            st.push(r);
            r=r->next;
        }
        int m=0;
        r=st.top();
        st.pop();
        m=max(m,r->val);
        while(!st.empty()){
            ListNode *x=st.top();
            st.pop();
            if(x->val>=m){
                m=max(m,x->val);
                x->next=r;
                r=x;
            }
        }
        return r;
    }
};