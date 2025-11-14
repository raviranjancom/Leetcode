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
    int count(TreeNode* root){
        if(root==nullptr){
            return 10001;
        }
        if(!root->left && !root->right){
            return 1;
        }
        return 1+min(count(root->left),count(root->right));
    }
    int minDepth(TreeNode* root){
        if(!root) return 0;
        return count(root);
    }
};
