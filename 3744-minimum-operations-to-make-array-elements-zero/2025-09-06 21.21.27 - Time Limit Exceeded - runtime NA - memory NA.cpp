class Solution {
public:
    int log4(int n) {
        return (int)((log(n)/log(4))+1);
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n=queries.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long total=0;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                total+=log4(j);
            }
            total=(ceil)((float)(total)/2.0);
            ans+=total;
        }
        return ans;
    }
};
