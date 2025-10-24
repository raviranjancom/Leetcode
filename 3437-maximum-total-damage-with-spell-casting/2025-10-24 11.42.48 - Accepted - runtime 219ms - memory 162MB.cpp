class Solution {
public:
    long long solve(vector<int>& power, int i,int n, vector<long long> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        //skip
        long long skip=solve(power,i+1,n,dp);
        // take
        int i_=upper_bound(begin(power)+i,end(power),power[i]+2)-begin(power);  // next valid index

        long long take=solve(power,i_,n,dp);

        int lb=lower_bound(begin(power)+i,end(power),power[i])-begin(power);
        int ub=upper_bound(begin(power)+i,end(power),power[i])-begin(power);
        
        return dp[i]=1LL*(max(skip,take+1LL*(ub-lb)*power[i]));
    }
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(),power.end());
        int n=power.size();
        vector<long long> dp(n,-1);
        return solve(power,0,n,dp);
    }
};
