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
    // checking the height if height is balaced and returning -1 if not balanced
    int height(TreeNode *r){
        if(r==nullptr){
            return 0;
        }
        int left=height(r->left);
        int right=height(r->right);
        if(left==-1 || right==-1) return -1;
        if(abs(right-left)>1) return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return height(root)!=-1;
    }
};