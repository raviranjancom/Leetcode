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
    void levelorder(TreeNode* r, vector<vector<int>> &ans){
        queue<TreeNode *> q;
        if(r){
            q.push({r});
        }
        int c=1;
        while(!q.empty()){
            queue<TreeNode *> t=q;
            vector<int> ds;
            while(!t.empty()){
                TreeNode* p=t.front();
                t.pop();
                q.pop();
                ds.push_back(p->val);
                if(c%2==0){
                    if(p->left) q.push(p->left);
                    if(p->right) q.push(p->right);
                }
                else{
                    if(p->right) q.push(p->right);
                    if(p->left) q.push(p->left);
                }
            }
            c++;
            ans.push_back(ds);
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelorder(root, ans);
        return ans;
    }
};