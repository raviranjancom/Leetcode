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
    TreeNode *solve(vector<int> &inorder, int start_in, int end_in, vector<int> &postorder, int start_post, int end_post, map<int,int> &mp){
        if(start_in > end_in || start_post < end_post){
            return nullptr;
        }
        TreeNode *root=new TreeNode(postorder[start_post]);
        int root_pos=mp[postorder[start_post]];
        int count=end_in - root_pos;

        root->left=solve(inorder, start_in, root_pos-1, postorder,start_post-count-1, end_post, mp);
        root->right=solve(inorder, root_pos+1, end_in, postorder,start_post-1,start_post-count, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        TreeNode *root=solve(inorder, 0, inorder.size()-1, postorder, postorder.size()-1, 0, mp);
        return root;
    }
};