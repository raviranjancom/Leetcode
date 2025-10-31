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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return root;
        TreeNode *ptr=root,*prev=root;
        while(ptr!=nullptr){
            if(ptr->val==key){
                TreeNode *last=ptr->right,*next=ptr;
                while(last && last->left){
                    next=last;
                    last=last->left;
                }
                if(last==nullptr){
                    if(prev->left==ptr){
                        prev->left=ptr->left;
                        ptr->left=nullptr; ptr->right=nullptr;
                    }
                    else{
                        prev->right=ptr->left;
                        ptr->left=nullptr; ptr->right=nullptr;
                    }
                    return root;
                }
                else{
                    if(prev->left==ptr){
                        prev->left=last;
                        last->left=ptr->left;
                        last->right=ptr->right;
                        ptr->left=nullptr; ptr->right=nullptr;
                        if(next==ptr){
                            last->right=nullptr;
                        }
                        else{
                            next->left=nullptr;
                        }
                    }
                    else{
                        prev->right=last;
                        last->left=ptr->left;
                        last->right=ptr->right;
                        ptr->left=nullptr; ptr->right=nullptr;
                        if(next==ptr){
                            last->right=nullptr;
                        }
                        else{
                            next->left=nullptr;
                        }
                    }
                    return root;
                }
            }
            else if(ptr->val>key){
                prev=ptr;
                ptr=ptr->left;
            }
            else{
                prev=ptr;
                ptr=ptr->right;
            }
        }
        return root;
    }
};
