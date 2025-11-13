class Solution {
public:
    int bfs(vector<vector<int>>& grid, int cr,int cc,int n,int m){
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[cr][cc]=true;
        queue<pair<pair<int,int>,int>> q;  // {row, col} => level
        q.push({{cr,cc},0});
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int level=q.front().second;
            q.pop();
            if(grid[r][c]==0) return level;
            vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
            for(auto &dir:directions){
                int x=r+dir[0];
                int y=c+dir[1];
                if(x>=0 && y>=0 && x<n && y<m && visited[x][y]==false){
                    q.push({{x,y},level+1});
                }
            }
        }
        return -1;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=bfs(mat,i,j,n,m);
            }
        }
        return ans;
    }
};
