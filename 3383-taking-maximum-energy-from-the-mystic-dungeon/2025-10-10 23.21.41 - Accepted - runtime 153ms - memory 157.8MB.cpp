class Solution {
public:
    int solve(vector<int>& energy, int k, int idx, int n, vector<int> &dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx]=energy[idx]+solve(energy,k,idx+k,n,dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size(),ans=INT_MIN;
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,solve(energy, k, i, n, dp));
        }
        return ans;
    }
};
