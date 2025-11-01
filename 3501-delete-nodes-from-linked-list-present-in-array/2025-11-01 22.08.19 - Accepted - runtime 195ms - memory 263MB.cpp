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
    ListNode *deletef(ListNode *head, set<int> &st){
        ListNode *dummy=new ListNode(-1),*last=head;
        dummy->next=head;
        head=dummy;
        while(last){
            auto it=st.find(last->val);
            if(it!=st.end()){
                dummy->next=last->next;
                last->next=nullptr;
                // delete last;
                last=dummy->next;
            }
            else{
                dummy=last;
                last=last->next;
            }
        }
        last=head;
        head=head->next;
        // delete last;
        return head;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        return deletef(head,st);
    }
};