class Solution {
public:
    int next(int key){
        return (key==0 || key==1)?2:0;
    }
    int solve(vector<vector<int>>& grid, int row,int col,int n,int m,int turn,int key,int x,int y){
        if(row>=n || col>=m || row<0 || col<0 || grid[row][col]!=key){
            return 0;
        }
        int a=1+solve(grid,row+x,col+y,n,m,turn,next(key),x,y);

        int nx=x,ny=y;
        if(nx==-1 && ny==-1){
            nx=-1;
            ny=1;
        }
        else if(nx==-1 && ny==1){
            nx=1;
            ny=1;
        }
        else if(nx==1 && ny==1){
            nx=1;
            ny=-1;
        }
        else if(nx==1 && ny==-1){
            nx=-1;
            ny=-1;
        }

        int b=(turn==1)?1+solve(grid,row+nx,col+ny,n,m,0,next(key),nx,ny):0;

        return max(a,b);
    }
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int top_left=solve(grid,i,j,n,m,1,grid[i][j],-1,-1);
                    int top_right=solve(grid,i,j,n,m,1,grid[i][j],-1,1);
                    int down_left=solve(grid,i,j,n,m,1,grid[i][j],1,-1);
                    int down_right=solve(grid,i,j,n,m,1,grid[i][j],1,1);
                    
                    ans=max(ans,max(max(top_left,top_right),max(down_left,down_right)));
                }
            }
        }
        return ans;
    }
};
