class Solution {
public:
    int Mod=1e9+7;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& grid,int k,int cr,int cc,int n,int m,int ans){
        if(cr==n && cc==m){
            if((ans+grid[cr][cc])%k==0) return 1;
            return 0;
        }
        else if(cr>n || cc>m){
            return 0;
        }
        else if(dp[cr][cc]!=-1){
            return dp[cr][cc];
        }
        ans+=grid[cr][cc];
        int x=solve(grid,k,cr+1,cc,n,m,ans);
        int y=solve(grid,k,cr,cc+1,n,m,ans);
        ans-=grid[cr][cc];

        return ((x%Mod)+(y%Mod))%Mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k){
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(grid,k,0,0,n,m,0);
    }
};
