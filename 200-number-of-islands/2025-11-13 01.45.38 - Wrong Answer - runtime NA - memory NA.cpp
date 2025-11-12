class Solution {
public:
    bool dfs(vector<vector<char>>& grid,int n,int m,int cr,int cc){
        if(grid[cr][cc]=='1'){
            grid[cr][cc]='2';
        }
        vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        bool ans=false;
        for(auto &it:directions){
            int x=cr+it[0];
            int y=cc+it[1];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1'){
                ans=true;
                dfs(grid,n,m,x,y);
            }
        }
        return ans;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(grid,n,m,i,j)) ans++;
            }
        }
        return ans;
    }
};