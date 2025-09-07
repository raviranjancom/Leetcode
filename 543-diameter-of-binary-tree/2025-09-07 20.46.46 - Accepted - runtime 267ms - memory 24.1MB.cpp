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
    int height(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);

        return 1+max(left,right);
    }
    int diameter(TreeNode *r){
        if(r){
            int h=height(r->left)+height(r->right);
            int x=diameter(r->left);
            int y=diameter(r->right);
            return max(h,max(x,y));
        }
        return 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root);
    }
};