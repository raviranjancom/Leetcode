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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *newnode=new TreeNode(val),*last=root,*prev=root;
        if(root==nullptr) return newnode;
        while(last!=nullptr){
            if(last->val>val){
                prev=last;
                last=last->left;
            }
            else{
                prev=last;
                last=last->right;
            }
        }
        if(prev->val>val){
            prev->left=newnode;
        }
        else{
            prev->right=newnode;
        }
        return root;
    }
};
