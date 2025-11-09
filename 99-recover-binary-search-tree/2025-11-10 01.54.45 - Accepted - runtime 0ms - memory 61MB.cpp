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
    TreeNode *first=nullptr,*middle=nullptr,*last=nullptr;
    TreeNode *prev=new TreeNode(INT_MIN);
    void inorder(TreeNode *root){
        if(root==nullptr) return ;
        inorder(root->left);
        if(prev->val>root->val){
            if(first==nullptr){
                first=prev;
                middle=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root){
        inorder(root);
        if(last==nullptr) swap(first->val,middle->val);
        else swap(first->val,last->val);
    }
};

// unsucessful attempt

// class Solution {
// public:
//     TreeNode *solve(TreeNode *root, long long low, long long high){
//         if(root==nullptr){
//             return nullptr;
//         }
//         if(root->val<=low || root->val>=high){
//             return root;
//         }
//         TreeNode *left=solve(root->left,low,root->val);
//         TreeNode *right=solve(root->right,root->val,high);

//         if(left!=nullptr && right!=nullptr){
//             int temp=left->val;
//             left->val=right->val;
//             right->val=temp;
//             return root;
//         }
//         else if(left!=nullptr && right==nullptr){
//             if(left->val>low && left->val<high){
//                 return left;
//             }
//             else{
//                 int temp=root->val;
//                 root->val=left->val;
//                 left->val=temp;
//                 return root;
//             }
//         }
//         else if(right!=nullptr && left==nullptr){
//             if(right->val>low && right->val<high){
//                 return right;
//             }
//             else{
//                 int temp=root->val;
//                 root->val=right->val;
//                 right->val=temp;
//                 return root;
//             }
//         }
//         else return nullptr;
//     }
//     void recoverTree(TreeNode* root) {
//         root=solve(root,INT_MIN,INT_MAX);
//     }
// };
