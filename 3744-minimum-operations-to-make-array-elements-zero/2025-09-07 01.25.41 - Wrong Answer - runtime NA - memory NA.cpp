class Solution {
public:
    long long minOperations(vector<vector<int>>& queries){
        int n=queries.size();
        int hash[16];
        for(int i=0;i<16;i++){
            hash[i]=pow(4,i);
        }

        long long ans=0;
        for(int i=0;i<n;i++){
            int start=queries[i][0];
            int end=queries[i][1];
            long long total=0;
            for(int j=1;j<16;j++){
                if(hash[j]>queries[i][1]){
                    total+=(end-start+1)*j;
                    break;
                }
                else{
                    total+=(hash[j]-start)*j;
                    start=hash[j];
                }
            }
            total = (long long)ceil((double)total / 2.0);
            ans+=total;
        }
        return ans;
    }
};
