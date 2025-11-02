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
        bool flag=true;
        while(last){
            if(last->left==nullptr){
                if(flag){
                    flag=false;
                    root=last;
                }
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
        TreeNode *prev=root;
        last=root->right;
        while(last){
            if(k==1){
                return prev->val;
            }
            if(last->val>prev->val){
                k--;
            }
            prev=last;
            last=last->right;
            
        }
        if(k==1){
            return prev->val;
        }
        return -1;
    }
};