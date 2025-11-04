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
    TreeNode *solve(vector<int> &preorder,int start_pre,int end_pre,vector<int> &inorder,int start_in,int end_in, map<int,int> &mp){
        if(start_pre>end_pre || start_in>end_in){
            return nullptr;
        }
        TreeNode *newnode=new TreeNode(preorder[start_pre]);
        int n=mp[preorder[start_pre]]-start_in;
        newnode->left=solve(preorder,start_pre+1,start_pre+n,inorder,start_in,mp[preorder[start_pre]]-1,mp);
        newnode->right=solve(preorder,start_pre+n+1,end_pre,inorder,mp[preorder[start_pre]]+1,end_in,mp);

        return newnode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder);
        sort(inorder.begin(),inorder.end());
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(preorder,0,inorder.size()-1,inorder,0,inorder.size()-1,mp);
    }
};