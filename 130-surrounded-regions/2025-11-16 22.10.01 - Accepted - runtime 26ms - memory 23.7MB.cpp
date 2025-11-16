class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<bool>> &visited, int cr, int cc,int n, int m){
        visited[cr][cc]=true;
        vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto dir:directions){
            int x=cr+dir[0];
            int y=cc+dir[1];
            if(x>=0 && x<n && y>=0 && y<m && visited[x][y]==false && board[cr][cc]=='O'){
                dfs(board,visited,x,y,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            dfs(board,visited,0,i,n,m);
            dfs(board,visited,n-1,i,n,m);
        }
        for(int i=0;i<n;i++){
            dfs(board,visited,i,0,n,m);
            dfs(board,visited,i,m-1,n,m);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
    }
};
