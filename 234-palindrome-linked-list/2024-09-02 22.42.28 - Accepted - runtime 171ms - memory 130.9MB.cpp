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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* p=head;
        while(p){
            v.push_back(p->val);
            p=p->next;
        }
        int n=size(v);
        int i=0,j=n-1;
        while(i<j){
            if(v[i]!=v[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
