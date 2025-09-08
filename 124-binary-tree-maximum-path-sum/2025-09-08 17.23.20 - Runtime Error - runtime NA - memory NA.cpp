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
    int sum(TreeNode *r){
        if(r->left==nullptr && r->right==nullptr){
            return r->val;
        }
        int left=sum(r->left);
        int right=sum(r->right);
        return max(r->val+left+right,max(left,right));
    }

    int maxPathSum(TreeNode* root){
        return sum(root);
    }
};
