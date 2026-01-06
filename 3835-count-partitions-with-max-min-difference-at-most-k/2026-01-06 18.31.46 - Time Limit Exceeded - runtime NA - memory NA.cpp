class Solution {
public:
    int mod=1e9+7;
    vector<int> dp;
    int solve(vector<int> &nums,int i,int k){
        int n=nums.size();
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=0;
        int minN=INT_MAX,maxN=INT_MIN;
        for(int j=i;j<n;j++){
            minN=min(minN,nums[j]);
            maxN=max(maxN,nums[j]);
            if(maxN-minN<=k){
                ans=(ans+solve(nums,j+1,k))%mod;
            }
            else break;
        }
        return dp[i]=ans;
    }
    int countPartitions(vector<int>& nums, int k){
        int n=nums.size();
        dp.resize(n,-1);
        return solve(nums,0,k);
    }
};
