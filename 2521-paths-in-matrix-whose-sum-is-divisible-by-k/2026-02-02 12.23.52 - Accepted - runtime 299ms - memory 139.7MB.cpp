class Solution {
public:
    int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid,int cr,int cc,int n,int m, int k,int sum){
        if(cr==n-1 && cc==m-1){
            return ((grid[cr][cc]+sum)%k==0)?1:0;
        }
        else if(cr==n || cc==m){
            return 0;
        }
        else if(dp[cr][cc][sum]!=-1){
            return dp[cr][cc][sum];
        }
        int newSum=(sum+grid[cr][cc])%k;
        int left=solve(grid,cr,cc+1,n,m,k,newSum);
        int down=solve(grid,cr+1,cc,n,m,k,newSum);
        return dp[cr][cc][sum]=(left+down)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k){
        int n=grid.size(),m=grid[0].size();
        dp.assign(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return solve(grid,0,0,n,m,k,0);
    }
};
