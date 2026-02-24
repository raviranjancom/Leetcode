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
    int H;
    int height(TreeNode *r){
        if(!r) return 0;
        return 1+(height(r->left),height(r->right));
    }
    void solve(TreeNode *r,int level,int &ans,int sum){
        if(!r){
            ans+=sum;
            return ;
        }
        int p=H-level-1;
        sum+=(pow(2,p)*(r->val));
        solve(r->left,level+1,ans,sum);
        solve(r->right,level+1,ans,sum);
        return ;
    }
    int sumRootToLeaf(TreeNode* root){
        H=height(root);
        int ans=0;
        solve(root,0,ans,0);
        return ans/2;
    }
};
