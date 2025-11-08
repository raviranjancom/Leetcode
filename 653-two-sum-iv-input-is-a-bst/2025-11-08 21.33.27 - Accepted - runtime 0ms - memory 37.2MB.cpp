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

class BST_Iterator{
    public:
        stack<TreeNode *> mystack;
        bool reverse=true;

        BST_Iterator(TreeNode *root, bool isreverse){
            reverse=isreverse;
            pushAll(root);
        }
        bool hasNext(){
            return !mystack.empty();
        }
        int Next(){
            TreeNode *t=mystack.top(); mystack.pop();
            if(reverse==false) pushAll(t->right);
            else pushAll(t->left);
            return t->val;
        }

    private:
        void pushAll(TreeNode *node){
            for(;node!=nullptr;){
                mystack.push(node);
                if(reverse==true) node=node->right;
                else node=node->left;
            }
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k){
        if(!root) return false;
        BST_Iterator left(root,false);
        BST_Iterator right(root,true);

        int i=left.Next();
        int j=right.Next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k){
                i=left.Next();
            }
            else{
                j=right.Next();
            }
        }
        return false;
    }
};