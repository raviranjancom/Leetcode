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
    void flatten(TreeNode* root) {
        solve(root);
    }
private:
    TreeNode *solve(TreeNode *root){
        if(root==nullptr) return nullptr;
        TreeNode *left=root->left,*right=root->right;
        root->left=nullptr;
        root->right=solve(left);
        TreeNode *last=root;
        while(last->right){
            last=last->right;
        }
        last->right=solve(right);
        return root;
    }
};
