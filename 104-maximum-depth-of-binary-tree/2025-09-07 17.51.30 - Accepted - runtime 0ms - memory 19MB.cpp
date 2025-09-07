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
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> q;
        if(root) q.push(root);
        int ans=0;
        while(!q.empty()){
            int y=q.size();
            while(y--){
                TreeNode *x=q.front(); q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            ans++;
        }
        return ans;
    }
};