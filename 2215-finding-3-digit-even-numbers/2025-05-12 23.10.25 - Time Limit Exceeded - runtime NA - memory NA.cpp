class Solution {
public:
    void fun(vector<int> &digits, set<int> &ans, vector<int> &ds, vector<bool> &marked){
        if(ds.size()==3){
            if(ds.back()%2==0){
                int x=ds[0]*100 + ds[1]*10 + ds[2];
                ans.insert(x);
            }
        }
        for(int i=0;i<digits.size();i++){
            if(ds.empty() && digits[i]==0) continue;
            else if(marked[i]==false){
                ds.push_back(digits[i]);
                marked[i]=true;
                fun(digits, ans, ds, marked);
                ds.pop_back();
                marked[i]=false;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ds, result;
        set<int> ans;
        vector<bool> marked(digits.size(), false);
        fun(digits, ans, ds, marked);
        
        for(int it : ans){
            result.push_back(it);
        }
        sort(result.begin(), result.end());
        return result;
    }
};