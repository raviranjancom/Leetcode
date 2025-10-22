class Solution {
public:
    int solve(vector<int>& energy, int k, vector<int> &dp, int i, int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=INT_MIN){
            return dp[i];
        }
        return dp[i]=energy[i] + solve(energy, k, dp, i+k, n);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int> dp(n,INT_MIN);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(energy, k, dp, i, n));
        }
        return ans;
    }
};
