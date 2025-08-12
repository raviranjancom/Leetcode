class Solution {
public:
    int fun(int num,int x,int sum,vector<vector<int>> &dp){
        if(sum==0){
            return 1;
        }
        else if(sum<0){
            return 0;
        }
        else if(pow(num,x)>sum){
            return 0;
        }
        else if(dp[sum][x]!=-1){
            return dp[num][sum];
        }
        int p=pow(num,x);
        sum-=p;
        int a=fun(num+1,x,sum,dp);
        sum+=p;
        int b=fun(num+1,x,sum,dp);
        return dp[num][sum]=a+b;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return fun(1,x,n,dp);
    }
};
