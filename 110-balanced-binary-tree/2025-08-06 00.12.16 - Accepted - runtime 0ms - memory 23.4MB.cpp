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
    int height(TreeNode* r){
        if(r==nullptr){
            return 0;
        }
        int x=height(r->left);
        int y=height(r->right);
        return (x>y)?x+1:y+1;
    }
    int balancefactor(TreeNode *r){
        return abs(height(r->left)-height(r->right));
    }
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root!=nullptr && balancefactor(root)>1) return false;
            if(root==nullptr){
                TreeNode *x=st.top();
                st.pop();
                root=x->right;
            }
            else{
                st.push(root);
                root=root->left;
            }
        }
        return true;
    }
};