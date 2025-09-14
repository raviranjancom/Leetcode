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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode *,pair<int,int>>> q;
        map<int,map<int,multiset<int>>> mp;
        if(root) q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode *,pair<int,int>> pi=q.front(); q.pop();
            TreeNode* node=pi.first;
            int x=pi.second.first;
            int y=pi.second.second;

            if(node->left){
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                q.push({node->right,{x+1,y+1}});
            }

            mp[x][y].insert(node->val);
        }

        vector<vector<int>> ans;
        for(auto it:mp){
            vector<int> ds;
            for(auto col:it.second){
                for(auto e:col.second){
                    ds.push_back(e);
                }
            }
            ans.push_back(ds);
        }
        return ans;
    }
};