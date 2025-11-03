/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void path(TreeNode *root,TreeNode *key,vector<TreeNode *> &ds){
        while(root){
            ds.push_back(root);
            if(root==key) break;
            else if(root->val>key->val){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path1,path2;
        path(root,p,path1);
        path(root,q,path2);
        TreeNode *ans=nullptr;
        for(int i=0;i<min(path1.size(),path2.size());i++){
            if(path1[i]==path2[i]) ans=path1[i];
            else break;
        }
        return ans;
    }
};
