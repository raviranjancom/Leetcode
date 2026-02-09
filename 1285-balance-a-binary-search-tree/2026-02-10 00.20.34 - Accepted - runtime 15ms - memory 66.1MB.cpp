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
    vector<int> ans;
    void preorder(TreeNode *r){
        if(!r) return ;
        preorder(r->left);
        ans.push_back(r->val);
        preorder(r->right);
        return ;
    }
    TreeNode *solve(int i,int j){
        if(i>j){
            return nullptr;
        }
        if(i==j){
            return new TreeNode(ans[i]);
        }
        int n=(i+j)/2;
        TreeNode *r=new TreeNode(ans[n]);
        r->left=solve(i,n-1);
        r->right=solve(n+1,j);
        return r;
    }
    TreeNode* balanceBST(TreeNode* root){
        preorder(root);
        return solve(0,ans.size()-1);
    }
};
