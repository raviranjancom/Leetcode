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
    string preserialize(TreeNode* r){
        if(r==nullptr) return "#";
        return to_string(r->val) + preserialize(r->left) + preserialize(r->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return (preserialize(p)==preserialize(q))? true :false;
    }
};