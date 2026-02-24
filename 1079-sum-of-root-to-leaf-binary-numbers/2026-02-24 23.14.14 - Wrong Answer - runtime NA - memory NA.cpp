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
    int calculate(string s){
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans+=(1<<(n-1-i));
        }
        return ans;
    }
    void solve(TreeNode *r,string s,int &ans){
        if(!r){
            ans+=calculate(s);
            return ;
        }
        char x=(r->val==1)?'1':'0';
        s.push_back(x);
        solve(r->left,s,ans);
        solve(r->right,s,ans);
        s.pop_back();
        return ;
    }
    int sumRootToLeaf(TreeNode* root){
        int ans=0;
        solve(root,"",ans);
        return ans/2;
    }
};
