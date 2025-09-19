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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode *,int>> q;
        q.push({root, 0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int min=q.front().second;
            int start,last,curr=0;
            for(int i=0;i<n;i++){
                auto x=q.front(); q.pop();
                TreeNode *node=x.first;
                int idx=x.second-min;

                if(node->left){
                    q.push({node->left, 2*idx+1});
                }
                if(node->right){
                    q.push({node->right, 2*idx+2});
                }
                if(i==0) start=idx;
                if(i==n-1) last=idx;
            }
            ans=max(ans, last-start+1);
        }

        return ans;
    }
};
