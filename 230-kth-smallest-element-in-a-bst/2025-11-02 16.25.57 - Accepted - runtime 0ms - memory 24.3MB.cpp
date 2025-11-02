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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *last=root;
        int count=0;
        while(last){
            if(last->left==nullptr){
                count++;
                if(count==k) return last->val;
                last=last->right;
            }
            else{
                TreeNode *ptr=last->left;
                while(ptr->right!=nullptr && ptr->right!=last){
                    ptr=ptr->right;
                }
                if(ptr->right==nullptr){
                    ptr->right=last;
                    TreeNode *temp=last->left;
                    last->left=nullptr;
                    last=temp;
                }
                else{
                    last=last->right;
                }
            }
        }
        return -1;
    }
};