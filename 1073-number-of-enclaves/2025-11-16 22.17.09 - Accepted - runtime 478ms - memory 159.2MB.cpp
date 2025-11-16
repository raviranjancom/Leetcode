class Solution {
public:
    void dfs(vector<vector<int>>& board, vector<vector<bool>> &visited, int cr, int cc,int n, int m){
        visited[cr][cc]=true;
        vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto dir:directions){
            int x=cr+dir[0];
            int y=cc+dir[1];
            if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==false && board[cr][cc]==1){
                dfs(board,visited,x,y,n,m);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            dfs(grid,visited,0,i,n,m);
            dfs(grid,visited,n-1,i,n,m);
        }
        for(int i=0;i<n;i++){
            dfs(grid,visited,i,0,n,m);
            dfs(grid,visited,i,m-1,n,m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==false){
                    ans++;
                }
            }
        }
        return ans;
    }
};
