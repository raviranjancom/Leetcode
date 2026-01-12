class Solution {
public:
    long long max(long long a,long long b){
        if(a>b) return a;
        return b;
    }
    long long maxSubarraySum(vector<int>& nums, int k){
        int n=nums.size();
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        // calculating prefix sum
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1]+nums[i];
        }
        long long ans=-1e9;
        for(int i=k-1;i<n;i++){
            int j=i-k;
            long long sum=-1e9;
            while(j>=0){
                long long x;
                sum=max(sum,prefix[i]-(x=(j>=0)?prefix[j]:0));
                j=j-k;
            }
            ans=max(ans,sum);
            if((i+1)%k==0) ans=max(ans,prefix[i]);
        }
        return ans;
    }
};
