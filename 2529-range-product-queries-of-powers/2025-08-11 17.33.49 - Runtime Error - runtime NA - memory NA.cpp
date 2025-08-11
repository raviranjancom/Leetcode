class Solution {
public:
    vector<int> num2binary(int n){
        int i=0;
        while(i<32 && pow(2,i)<=n){
            i++;
        }
        vector<int> ans;
        while(i>=0){
            int x=pow(2,i);
            if(x<=n){
                ans.push_back(x);
                n=n-x;
            }
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers=num2binary(n);
        for(int i=0;i<powers.size();i++){
            cout<<powers[i]<<" ";
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int low=queries[i][0];
            int high=queries[i][1];
            int x=1;
            for(int j=low;j<=high;j++){
                x=x*powers[j];
            }
            ans.push_back(x);
        }
        return ans;
    }
};
