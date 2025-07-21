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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        queue<TreeNode *> st;
        vector<int> ds;
        TreeNode* r=root;
        st.push(r);
        queue<TreeNode *> temp;
        while(!st.empty()){
            r=st.front();
            st.pop();
            if(r){
                ds.push_back(r->val);
            }
            if(r->right){
                temp.push(r->right);
            }
            if(r->left){
                temp.push(r->left);
            }
            if(st.empty()){
                reverse(ds.begin(),ds.end());
                ans.push_back(ds);
                st=temp;
                queue<TreeNode *> x;
                temp=x;
                vector<int> t;
                ds=t;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
