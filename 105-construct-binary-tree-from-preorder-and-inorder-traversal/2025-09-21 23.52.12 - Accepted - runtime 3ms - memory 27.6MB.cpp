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
    TreeNode *solve(vector<int> &inorder, int start_in, int end_in, vector<int> &preorder, int start_pre, int end_pre, map<int,int> &mp){
        if(start_in > end_in || start_pre > end_pre){
            return nullptr;
        }
        TreeNode *root=new TreeNode(preorder[start_pre]);
        int in_root=mp[preorder[start_pre]];
        int left_count=in_root - start_in;

        root->left=solve(inorder, start_in, in_root-1, preorder, start_pre+1, start_pre+left_count, mp);
        root->right=solve(inorder, in_root+1, end_in, preorder, start_pre+1+left_count, end_pre, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        TreeNode *root = solve(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mp);
        return root;
    }
};