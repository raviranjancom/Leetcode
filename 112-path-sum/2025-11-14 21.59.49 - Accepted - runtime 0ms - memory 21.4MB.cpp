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
    bool hasPathSum(TreeNode* root, int targetSum){
        if(root==nullptr) return false;
        targetSum-=root->val;
        if(!root->left && !root->right && targetSum==0) return true;
        if(!root->left && !root->right && targetSum!=0) return false;
        int x=hasPathSum(root->left,targetSum);
        int y=hasPathSum(root->right,targetSum);
        return x || y;
    }
};
