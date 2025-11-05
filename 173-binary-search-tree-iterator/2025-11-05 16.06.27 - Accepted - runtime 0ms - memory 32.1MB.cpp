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
class BSTIterator {
public:
    int i=-1;
    vector<int> ds;
    void inorder(TreeNode *r){
        if(r){
            inorder(r->left);
            ds.push_back(r->val);
            inorder(r->right);
        }
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        i++;
        return ds[i];
    }
    
    bool hasNext() {
        if(i+1>=ds.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */