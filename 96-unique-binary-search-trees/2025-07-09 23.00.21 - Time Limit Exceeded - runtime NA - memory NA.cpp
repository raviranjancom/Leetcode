class Solution {
public:
    class node{
        public:
            int data;
            node *left,*right;
            node(int v){
                data=v;
                left=right=nullptr;
            }
    };
    void fun(vector<int> qus, vector<int> &ds, vector<vector<int>> &nums, vector<bool> &marked){
        if(ds.size()==qus.size()){
            nums.push_back(ds);
            return ;
        }
        for(int i=0;i<qus.size();i++){
            if(marked[qus[i]]==false){
                marked[qus[i]]=true;
                ds.push_back(i);
                fun(qus,ds,nums,marked);
                marked[qus[i]]=false;
                ds.pop_back();
            }
        }
    }
    node *create(vector<int> qus){
        int n=qus.size();
        node* r=new node(qus[0]);
        node *last=r,*root=r;
        for(int i=1;i<n;i++){
            r=root;
            while(r){
                if(r->data > qus[i]){
                    last=r;
                    r=r->left;
                }
                else{
                    last=r;
                    r=r->right;
                }
            }
            node* t=new node(qus[i]);
            (qus[i]>last->data)?last->right=t:last->left=t;
        }
        return root;
    }
    string serialize(node* root) {
        if (!root) return "#";
        return to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    void count(vector<vector<int>> nums, set<string> &st){
        for(auto &it : nums){
            node *root = create(it);
            st.insert(serialize(root));
        }
    }


    int numTrees(int n) {
        vector<int> qus,ds;
        for(int i=1;i<=n;i++){
            qus.push_back(i);
        }
        vector<bool> marked(n,false);
        vector<vector<int>> nums;
        fun(qus,ds,nums,marked);
        set<string> st;
        count(nums,st);
        return st.size();
    }
};
