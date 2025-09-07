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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode *,int>> st;
        vector<int> preorder,inorder,postorder;
        if(root) st.push({root,1});
        while(!st.empty()){
            pair<TreeNode *,int> x=st.top(); st.pop();
            if(x.second==1){
                x.second=2;
                st.push(x);
                preorder.push_back(x.first->val);
                if(x.first->left){
                    st.push({x.first->left,1});
                }
            }
            else if(x.second==2){
                x.second=3;
                st.push(x);
                inorder.push_back(x.first->val);
                if(x.first->right){
                    st.push({x.first->right,1});
                }
            }
            else{
                postorder.push_back(x.first->val);
            }
        }
        return postorder;
    }
};