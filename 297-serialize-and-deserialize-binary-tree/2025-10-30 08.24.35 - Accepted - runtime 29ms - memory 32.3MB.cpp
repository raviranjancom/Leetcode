/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==nullptr){
            return "";
        }
        string ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *x=q.front(); q.pop();
            if(x!=nullptr){
                q.push(x->left);
                q.push(x->right);
            }
            if(x==nullptr){
                ans+="$,";
            }
            else{
                ans+=to_string(x->val)+",";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data);
        string ans;
        getline(s,ans,',');
        queue<TreeNode*> q;
        TreeNode *root=new TreeNode(stoi(ans));
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front(); q.pop();

            getline(s,ans,',');
            if(ans=="$"){
                node->left=nullptr;
            }
            else{
                TreeNode *leftnode=new TreeNode(stoi(ans));
                node->left=leftnode;
                q.push(leftnode);
            }
            getline(s,ans,',');
            if(ans=="$"){
                node->right=nullptr;
            }
            else{
                TreeNode *rightnode=new TreeNode(stoi(ans));
                node->right=rightnode;
                q.push(rightnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));