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
    bool fun(TreeNode* root, long long low, long long high){
        if(!root){
            return true;
        }
        else if(root->val <= low || root->val >= high){
            return false;
        }
        return fun(root->left,low,root->val) && fun(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
        return fun(root,INT64_MIN,INT64_MAX);
    }
};
