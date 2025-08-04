class Solution {
public:
    void fun(int n, int k, vector<bool> &marked,vector<string> &ans, string &ds){
        if(ds.size()>=n){
            ans.push_back(ds);
            return ;
        }
        for(int i=1;i<=n;i++){
            if(marked[i]==false){
                ds.push_back(char(i+48));
                marked[i]=true;
                fun(n,k,marked,ans,ds);
                ds.pop_back();
                marked[i]=false;
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<bool> marked(n,false);
        string ds;
        vector<string> ans;
        fun(n, k, marked, ans, ds);
        return ans[k-1];
    }
};
