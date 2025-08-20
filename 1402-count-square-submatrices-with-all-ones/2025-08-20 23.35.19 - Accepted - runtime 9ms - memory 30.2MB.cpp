class Solution {
public:
    vector<vector<int>> dp;
    int min(int a,int b){
        return(a<b)?a:b;
    }
    
    int fun(vector<vector<int>>& matrix,int n,int m,int i,int j){
        if(i>=n || j>=m || matrix[i][j]==0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=1+fun(matrix,n,m,i,j+1);
        int down=1+fun(matrix,n,m,i+1,j);
        int diagonal=1+fun(matrix,n,m,i+1,j+1);
        return dp[i][j]=min(right,min(down,diagonal));
    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        dp.assign(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=fun(matrix,n,m,i,j);
            }
        }
        return ans;
    }
};
