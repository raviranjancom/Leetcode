class Solution {
public:
    long long minOperations(vector<vector<int>>& queries){
        int n = queries.size();
        long long hash[16];
        for(int i=0;i<16;i++){
            hash[i] = (long long)pow(4, i);
        }

        long long ans = 0;
        for(int i=0;i<n;i++){
            int l = queries[i][0];
            int r = queries[i][1];

            // compute getOps(r)
            long long totalEnd = 0;
            if(r > 0){
                int start = 1;
                for(int j=1;j<16;j++){
                    if(hash[j] > r){
                        totalEnd += (long long)(r - start + 1) * j;
                        break;
                    } else {
                        totalEnd += (long long)(hash[j] - start) * j;
                        start = hash[j];
                    }
                }
            }

            // compute getOps(l-1)
            long long totalStart = 0;
            if(l > 1){
                int upto = l - 1;
                int start = 1;
                for(int j=1;j<16;j++){
                    if(hash[j] > upto){
                        totalStart += (long long)(upto - start + 1) * j;
                        break;
                    } else {
                        totalStart += (long long)(hash[j] - start) * j;
                        start = hash[j];
                    }
                }
            }

            // final contribution
            long long total = (totalEnd - totalStart + 1) / 2;
            ans += total;
        }
        return ans;
    }
};
