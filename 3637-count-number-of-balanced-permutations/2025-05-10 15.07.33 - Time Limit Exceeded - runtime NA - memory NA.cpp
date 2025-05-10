class Solution {
public:
    void permutation(set<vector<int>> &ans, vector<int> &ds, vector<int> &qus, vector<bool> &marked){
        if(qus.size()==ds.size()){
            ans.insert(ds);
            return ;
        }
        for(int i=0;i<qus.size();i++){
            if(marked[i]==false){
                ds.push_back(qus[i]);
                marked[i]=true;
                permutation(ans, ds, qus, marked);
                ds.pop_back();
                marked[i]=false;
            }
        }
    }

    int check(const vector<int>& v){
        int a=0,b=0;
        for(int i=0;i<v.size();i++){
            if(i%2==0){
                a+=v[i];
            }
            else{
                b+=v[i];
            }
        }
        return (a==b)?1:0;
    }
    int countBalancedPermutations(string num) {
        vector<bool> marked(num.length(), false);
        vector<int> qus, ds;
        for(int i=0;i<num.length();i++){
            qus.push_back(num[i]-48);
        }
        set<vector<int>> ans;
        permutation(ans, ds, qus, marked);
        int result=0;
        for(auto it : ans){
            result+=check(it);
        }
        return result;
    }
};
