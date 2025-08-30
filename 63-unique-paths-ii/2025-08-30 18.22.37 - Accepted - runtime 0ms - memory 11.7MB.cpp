class Solution {
public:
    
    int solve(vector<vector<int>>& obstacleGrid,int cr,int cc,int n,int m,vector<vector<int>> &dp){
        if(cr>=n || cc>=m || obstacleGrid[cr][cc]==1){
            return 0;
        }
        else if(cr==n-1 && cc==m-1){
            return 1;
        }

        else if(dp[cr][cc]!=-1){
            return dp[cr][cc];
        }

        return dp[cr][cc]=solve(obstacleGrid,cr+1,cc,n,m,dp)+solve(obstacleGrid,cr,cc+1,n,m,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(obstacleGrid,0,0,n,m,dp);
    }
};
