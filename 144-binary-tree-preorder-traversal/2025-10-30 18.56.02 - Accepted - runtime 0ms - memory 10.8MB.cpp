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
    vector<int> preorderTraversal(TreeNode* root) {
        // Moris Traversal
        vector<int> ans;
        while(root){
            if(root->left==nullptr){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                TreeNode *y=root->left;
                while(y->right!=nullptr && y->right!=root){
                    y=y->right;
                }
                if(y->right==nullptr){
                    ans.push_back(root->val);
                    y->right=root;
                    root=root->left;
                }
                else{
                    y->right=nullptr;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};
