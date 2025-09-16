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
    void solve(TreeNode *r,int score,vector<int> &ans){
        if(!r){
            return ;
        }
        if(score==ans.size()){
            ans.push_back(r->val);
        }
        solve(r->right,score+1,ans);
        solve(r->left,score+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 0, ans);
        return ans;
    }
};