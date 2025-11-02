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
    bool preorder(TreeNode *root,long long low, long long high){
        if(!root) return true;
        else if(root->val>=high || root->val<=low) return false;
        return preorder(root->left,low,root->val) && preorder(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        return preorder(root,INT64_MIN,INT64_MAX);
    }
};
