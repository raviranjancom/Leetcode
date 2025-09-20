/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapping(TreeNode *r,unordered_map<TreeNode *,bool> &marked, unordered_map<TreeNode *,TreeNode *> &mp){
        if(r){
            marked[r]=false;
            if(r->left) mp[r->left]=r;
            if(r->right) mp[r->right]=r;
            mapping(r->left,marked, mp);
            mapping(r->right,marked, mp);
        }
    }
    void solve(TreeNode* r, TreeNode* target, int k, vector<int> &ans,unordered_map<TreeNode *, bool> &marked, unordered_map<TreeNode *,TreeNode *> &mp){
        if(target==nullptr){
            return ;
        }
        if(marked[target]==true){
            return ;
        }
        if(k==0){
            ans.push_back(target->val);
            return ;
        }
        marked[target]=true;
        solve(r, target->left, k-1, ans,marked,mp);
        solve(r, target->right, k-1, ans,marked,mp);
        if(r!=target) solve(r ,mp[target] ,k-1, ans,marked,mp);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *, TreeNode *> mp;
        unordered_map<TreeNode *, bool> marked;
        mapping(root,marked,mp);

        vector<int> ans;
        solve(root, target, k, ans, marked, mp);
        return ans;
    }
};
