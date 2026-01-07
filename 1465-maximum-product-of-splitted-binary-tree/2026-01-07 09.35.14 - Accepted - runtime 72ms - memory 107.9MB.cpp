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
    int mod=1e9+7;
    unordered_map<TreeNode *,int> mp;
    long long calculateSum(TreeNode *root){
        if(!root) return 0;
        if(mp.find(root)!=mp.end()){
            return mp[root];
        }
        long long left=calculateSum(root->left);
        long long right=calculateSum(root->right);
        return mp[root]=(root->val+left+right);
    }
    long long solve(TreeNode *root,long long &total){
        if(!root){
            return 0;
        }
        long long left=solve(root->left,total);
        long long right=solve(root->right,total);
        return max(((total-mp[root])*mp[root]),max(left,right));
    }
    int maxProduct(TreeNode* root){
        long long total=calculateSum(root);
        return solve(root,total)%mod;
    }
};
