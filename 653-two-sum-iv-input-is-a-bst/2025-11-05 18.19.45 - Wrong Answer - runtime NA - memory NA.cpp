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
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool> mp;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *x=st.top();
            if(x->left){
                st.push(x->left);
            }
            else{
                auto it=mp.find(k-x->val);
                if(it!=mp.end()) return true;
                mp[x->val]=true;
                while(!st.empty() && st.top()->right==nullptr){
                    auto jt=mp.find(k-st.top()->val);
                    if(jt!=mp.end()) return true;
                    mp[st.top()->val]=true;
                    st.pop();
                }
                TreeNode* t;
                if(st.empty()==false){
                    t=st.top(); st.pop();
                    st.push(t->right);
                }
            }
        }
        return false;
    }
};
