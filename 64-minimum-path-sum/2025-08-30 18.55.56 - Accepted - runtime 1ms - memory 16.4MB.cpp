class Solution {
public:
    int solve(vector<vector<int>>& grid,vector<vector<int>> &dp,int cr,int cc,int n,int m){
        if(cr>=n || cc>=m){
            return -1;
        }
        else if(cr==n-1 && cc==m-1){
            return dp[cr][cc]=grid[cr][cc];
        }
        else if(dp[cr][cc]!=-1){
            return dp[cr][cc];
        }
        int left=solve(grid,dp,cr+1,cc,n,m);
        int down=solve(grid,dp,cr,cc+1,n,m);

        int ans=grid[cr][cc];
        if(down==-1 || (left!=-1 && left<=down)){
            ans+=left;
        }
        else{
            ans+=down;
        }
        return dp[cr][cc]=ans;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(grid,dp,0,0,n,m);
    }
};
