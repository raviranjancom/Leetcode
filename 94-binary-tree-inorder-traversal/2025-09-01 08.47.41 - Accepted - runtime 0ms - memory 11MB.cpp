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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> ans;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                TreeNode *x=st.top(); st.pop();
                root=x;
                ans.push_back(x->val);
                root=root->right;
            }
        }
        return ans;
    }
};
