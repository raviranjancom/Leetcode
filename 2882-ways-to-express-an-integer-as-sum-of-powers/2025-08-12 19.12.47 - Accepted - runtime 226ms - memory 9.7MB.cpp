class Solution {
public:
    int M = 1e9+7;
    int dp[301][301];
    int fun(int num,int x,int sum){
        if(sum==0){
            return 1;
        }
        else if(sum<0){
            return 0;
        }
        else if(pow(num,x)>sum){
            return 0;
        }
        else if(dp[num][sum]!=-1){
            return dp[num][sum];
        }
        int p=pow(num,x);
        sum-=p;
        int a=fun(num+1,x,sum);
        sum+=p;
        int b=fun(num+1,x,sum);
        return dp[num][sum]=(a+b)%M;
    }
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return fun(1,x,n);
    }
};
