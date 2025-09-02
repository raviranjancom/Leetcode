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
        // double stack method
        vector<int> ans;
        if(root==nullptr) return ans;
        stack<TreeNode *> st1,st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top(); st1.pop();
            st2.push(root);
            if(root->left) st1.push(root->left);
            if(root->right) st1.push(root->right);
        }
        while(!st2.empty()){
            TreeNode* x=st2.top(); st2.pop();
            ans.push_back(x->val);
        }
        return ans;
    }
};
