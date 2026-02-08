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
    unordered_map<TreeNode *,int> dp;
    int height(TreeNode *r){
        if(r==nullptr) return 0;
        //if(dp[r]!=-1) return dp[r];
        return dp[r]=max(height(r->left),height(r->right))+1;
    }
    int H(TreeNode *r){
        return (r==nullptr)?0:dp[r];
    }
    bool isBalanced(TreeNode* root){
        height(root);
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *x=q.front(); q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                if(abs(height(x->right)-height(x->left))>1) return false;
            }
        }
        return true;
    }
};
