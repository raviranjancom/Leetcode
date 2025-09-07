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
    bool preorder(TreeNode *r, TreeNode *p){
        if((!r && p) || (r && !p)) return false;
        if(r && p){
            if(r->val!=p->val) return false;
            return preorder(r->left,p->left) && preorder(r->right,p->right);;
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p,q);
    }
};