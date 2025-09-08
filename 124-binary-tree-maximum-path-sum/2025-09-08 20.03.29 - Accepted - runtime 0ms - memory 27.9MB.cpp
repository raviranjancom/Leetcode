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
    int solve(TreeNode *r,int &sum){
        if(!r) return 0;
        int left=max(0,solve(r->left,sum));
        int right=max(0,solve(r->right,sum));
        sum=max(sum,r->val+left+right);
        return r->val+max(left,right);
    }

    int maxPathSum(TreeNode* root){
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};
