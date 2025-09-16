/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path(TreeNode *r, TreeNode* key, vector<TreeNode *> &ans){
        if(!r) return false;

        ans.push_back(r);
        if(r==key){
            return true;
        }
        if(path(r->left, key, ans) || path(r->right, key, ans)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> v1,v2;
        path(root, p, v1);
        path(root, q, v2);

        int i=0;
        while(i < v1.size() && i < v2.size() && v1[i]==v2[i]){
            i++;
        }
        return v1[i-1];
    }
};