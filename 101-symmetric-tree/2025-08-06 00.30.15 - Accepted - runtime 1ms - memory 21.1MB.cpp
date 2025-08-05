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
    string fun1(TreeNode *r){
        if(r==nullptr){
            return "#";
        }
        return to_string(r->val)+fun1(r->left)+fun1(r->right);
    }
    string fun2(TreeNode *r){
        if(r==nullptr){
            return "#";
        }
        return to_string(r->val)+fun2(r->right)+fun2(r->left);
    }

    bool isSymmetric(TreeNode* root) {
        string x=fun1(root->left);
        string y=fun2(root->right);
        cout<<x<<"  "<<y;
        return (x==y)? true: false;
    }
};