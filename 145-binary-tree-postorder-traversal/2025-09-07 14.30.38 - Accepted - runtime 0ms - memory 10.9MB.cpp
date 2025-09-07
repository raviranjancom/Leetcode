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
        stack<TreeNode *> st;
        vector<int> ans;
        while(!st.empty() || root){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                TreeNode *temp=st.top()->right;
                if(temp){
                    root=temp;
                }
                else{
                    while(!st.empty() && st.top()->right==temp){
                        ans.push_back(st.top()->val);
                        temp=st.top(); st.pop();
                    }
                }
            }
        }
        return ans;
    }
};