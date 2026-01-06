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
    int maxLevelSum(TreeNode* root) {
        int ans=-1e9;
        int level=0,res;
        queue<TreeNode *> q;
        if(root) q.push(root);
        while(!q.empty()){
            level++;
            int k=q.size();
            int sum=0;
            while(k--){
                TreeNode *x=q.front(); q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                sum+=x->val;
            }
            if(ans<sum){
                ans=sum;
                res=level;
            }
        }
        return res;
    }
};
