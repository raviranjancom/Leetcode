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
    // morris traversal
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr=root;
        while(curr!=nullptr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode *leftnode=curr->left;
                while(leftnode->right!=nullptr){
                    leftnode=leftnode->right;
                }
                leftnode->right=curr;
                TreeNode *temp=curr;
                curr=curr->left;
                temp->left=nullptr;
            }
        }
        return ans;
    }
};