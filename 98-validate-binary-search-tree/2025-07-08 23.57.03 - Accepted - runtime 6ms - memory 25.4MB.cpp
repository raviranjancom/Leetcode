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
    void inorder(TreeNode* root, vector<int> &ds, set<int> &st){
        if(root){
            inorder(root->left, ds, st);
            st.insert(root->val);
            ds.push_back(root->val);
            inorder(root->right, ds, st);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> ds;
        set<int> st;
        inorder(root,ds,st);
        vector<int> bs=ds;
        sort(ds.begin(),ds.end());
        if(ds==bs && st.size()==ds.size()) return true;
        return false;
    }
};
