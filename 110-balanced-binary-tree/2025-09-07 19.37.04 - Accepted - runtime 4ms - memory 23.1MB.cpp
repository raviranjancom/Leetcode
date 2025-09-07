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
    // checking the balance factor at each node
    int height(TreeNode *r){
        if(r==nullptr){
            return 0;
        }
        return 1+max(height(r->left),height(r->right));
    }
    bool isBalanced(TreeNode* root) {
        if(root){
            if(abs(height(root->left) - height(root->right))>1) return false;
            bool x=isBalanced(root->left);
            bool y=isBalanced(root->right);
            return x & y;
        }
        return true;
    }
};