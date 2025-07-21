class Solution {
public:
    int maze(int cr, int cc, int row, int col, vector<vector<int>> &dp){
        if(cr==row && cc==col){
            return 1;
        }
        if(cr>row || cc>col) return 0;
        if(dp[cr][cc]==-1){
            int x=maze(cr+1, cc, row, col, dp);
            int y=maze(cr, cc+1, row, col, dp);
            dp[cr][cc]=x+y;
            return x+y;
        }
        return dp[cr][cc];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return maze(0,0,m-1,n-1,dp);
    }
};
