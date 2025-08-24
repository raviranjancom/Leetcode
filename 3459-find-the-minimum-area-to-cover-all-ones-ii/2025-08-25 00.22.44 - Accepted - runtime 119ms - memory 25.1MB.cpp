class Solution {
public:
    int minimumArea(int start_row,int end_row,int start_col,int end_col,vector<vector<int>> &grid){
        int n=grid.size(),m=grid[0].size();
        int min_row=n,max_row=-1,min_col=m,max_col=-1;
        for(int i=start_row;i<end_row;i++){
            for(int j=start_col;j<end_col;j++){
                if(grid[i][j]==1){
                    min_row=min(min_row,i);
                    max_row=max(max_row,i);
                    min_col=min(min_col,j);
                    max_col=max(max_col,j);
                }
            }
        }
        return (max_row-min_row+1)*(max_col-min_col+1);
    }
    int minimumSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=INT_MAX;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                ans=min(ans,minimumArea(0,i,0,m,grid)+minimumArea(i,n,0,j,grid)+minimumArea(i,n,j,m,grid));
                ans=min(ans,minimumArea(0,i,0,j,grid)+minimumArea(0,i,j,m,grid)+minimumArea(i,n,0,m,grid));
            }
        }

        for(int j=1;j<m;j++){
            for(int i=1;i<n;i++){
                ans=min(ans,minimumArea(0,n,0,j,grid)+minimumArea(0,i,j,m,grid)+minimumArea(i,n,j,m,grid));
                ans=min(ans,minimumArea(0,i,0,j,grid)+minimumArea(i,n,0,j,grid)+minimumArea(0,n,j,m,grid));
            }
        }

        for(int i=1;i<n-1;i++){
            for(int j=2;j<n;j++){
                ans=min(ans,minimumArea(0,i,0,m,grid)+minimumArea(i,j,0,m,grid)+minimumArea(j,n,0,m,grid));
            }
        }

        for(int i=1;i<m-1;i++){
            for(int j=2;j<m;j++){
                ans=min(ans,minimumArea(0,n,0,i,grid)+minimumArea(0,n,i,j,grid)+minimumArea(0,n,j,m,grid));
            }
        }

        return ans;
    }
};
