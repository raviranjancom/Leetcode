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
    void preorder(TreeNode* r,vector<int> &v){
        if(r){
            v.push_back(r->val);
            preorder(r->left,v);
            preorder(r->right,v);
        }
    }

    void inorder(TreeNode* r,vector<int> &v){
        if(r){
            inorder(r->left,v);
            v.push_back(r->val);
            inorder(r->right,v);
        }
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1,v2,v3,v4;
        preorder(p,v1);
        inorder(p,v2);

        preorder(q,v3);
        inorder(q,v4);

        return (v1==v3 && v2==v4)? true:false;
    }
};