/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* r, int k) {
        stack<TreeNode *> st;
        unordered_map<int,bool> mp;
        while(r || !st.empty()){
            if(r){
                st.push(r);
                r=r->left;
            }
            else{
                r=st.top(); st.pop();
                auto it=mp.find(k-r->val);
                if(it!=mp.end()) return true;
                mp[r->val]=true;
                r=r->right;
            }
        }
        return false;
    }
};