class Solution {
public:
    vector<int> num2binary(int n){
        vector<int> ans;
        for(int i=0;i<32;i++){
            if(n&(1<<i)){
                ans.push_back(1<<i);
            }
        }
        return ans;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod=1000000007;
        vector<int> powers=num2binary(n);
        for(int i=0;i<powers.size();i++){
            cout<<powers[i]<<" ";
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int low=queries[i][0];
            int high=queries[i][1];
            long long int x=1;
            for(int j=low;j<=high;j++){
                x=(x*powers[j])%mod;
            }
            ans.push_back(x);
        }
        return ans;
    }
};
