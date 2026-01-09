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
    int fun(TreeNode *r,TreeNode* &ans,int level,int &depth){
        if(!r){
            return 0;
        }
        int x=fun(r->left,ans,level+1,depth);
        int y=fun(r->right,ans,level+1,depth);
        if(x==y && level+x>=depth){
            ans=r;
            depth=level+x;
        }
        return 1+max(x,y);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        TreeNode *ans=nullptr;
        int depth=0;
        fun(root,ans,0,depth);
        return ans;
    }
};
