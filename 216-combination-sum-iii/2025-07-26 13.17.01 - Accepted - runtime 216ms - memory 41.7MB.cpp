class Solution {
public:
    void combination(int sum,int len,vector<int> &ds,set<vector<int>> &mp,vector<bool> &mark){
        if(ds.size()==len){
            if(sum==0){
                vector<int> x=ds;
                sort(x.begin(),x.end());
                mp.insert(x);
            }
            return ;
        }
        for(int i=1;i<10;i++){
            if(!mark[i]){
                if(sum>=i){
                    mark[i]=true;
                    sum-=i;
                    ds.push_back(i);
                    combination(sum,len,ds,mp,mark);
                    ds.pop_back();
                    sum+=i;
                    mark[i]=false;
                }
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int> ds;
         vector<vector<int>> ans;
         vector<bool> mark(10,false);
         set<vector<int>> mp;
         combination(n,k,ds,mp,mark);
         for(auto it:mp){
            ans.push_back(it);
         }
         return ans;
    }
};
