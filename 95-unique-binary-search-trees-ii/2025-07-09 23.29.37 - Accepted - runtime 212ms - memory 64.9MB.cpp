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
    void fun(vector<int> qus, vector<int> &ds, vector<vector<int>> &nums, vector<bool> &marked){
        if(ds.size()==qus.size()){
            nums.push_back(ds);
            return ;
        }
        for(int i=0;i<qus.size();i++){
            if(marked[qus[i]]==false){
                marked[qus[i]]=true;
                ds.push_back(qus[i]);
                fun(qus,ds,nums,marked);
                marked[qus[i]]=false;
                ds.pop_back();
            }
        }
    }

    TreeNode *create(vector<int> qus){
        int n=qus.size();
        TreeNode* r=new TreeNode(qus[0]);
        TreeNode *last=r,*root=r;
        for(size_t i=1;i<n;i++){
            r=root;
            while(r){
                if(r->val > qus[i]){
                    last=r;
                    r=r->left;
                }
                else{
                    last=r;
                    r=r->right;
                }
            }
            TreeNode* t=new TreeNode(qus[i]);
            (qus[i]>last->val)?last->right=t:last->left=t;
        }
        return root;
    }
    string serialize(TreeNode* root) {
        if (!root) return "#";
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    void count(vector<vector<int>> nums, set<string> &st, vector<TreeNode *> &ans){
        for(auto &it : nums){
            TreeNode *root = create(it);
            size_t x=st.size();
            st.insert(serialize(root));
            if(x<st.size()){
                ans.push_back(root);
            }
        }
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<int> qus,ds;
        for(int i=1;i<=n;i++){
            qus.push_back(i);
        }
        vector<bool> marked(n,false);
        vector<vector<int>> nums;
        vector<TreeNode *> ans;
        fun(qus,ds,nums,marked);
        set<string> st;
        count(nums,st, ans);
        return ans;
    }
};