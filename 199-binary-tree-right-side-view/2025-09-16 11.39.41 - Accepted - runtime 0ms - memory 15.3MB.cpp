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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;
        if(root) q.push({root, 0});

        while(!q.empty()){
            pair<TreeNode *, int> t=q.front(); q.pop();
            TreeNode *node=t.first;
            int y=t.second;
            mp[y]=node->val;

            if(node->left){
                q.push({node->left, y+1});
            }
            if(node->right){
                q.push({node->right, y+1});
            }
        }
        vector<int> ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};