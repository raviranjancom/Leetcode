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
    int right_height(TreeNode* r){
        if(!r){
            return 0;
        }
        return 1+min(right_height(r->left), right_height(r->right));
    }
    int left_height(TreeNode* r){
        if(!r){
            return 0;
        }
        return 1+max(left_height(r->left), left_height(r->right));
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(left_height(root->left)==right_height(root->right)){
            return pow(2,left_height(root))-1;
        }
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};