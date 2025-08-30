class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int cr,int cc,int n,int m){
        if(cr==n-1 && cc==m-1){
            return 1;
        }
        else if(cr>=n || cc>=m || obstacleGrid[cr][cc]==1){
            return 0;
        }
        return solve(obstacleGrid,cr+1,cc,n,m)+solve(obstacleGrid,cr,cc+1,n,m);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(),m=obstacleGrid[0].size();
        return solve(obstacleGrid,0,0,n,m);
    }
};