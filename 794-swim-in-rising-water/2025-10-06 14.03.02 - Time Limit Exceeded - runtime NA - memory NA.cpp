class Solution {
public:
    void solve(vector<vector<int>>& grid,vector<vector<bool>> &mark,int cr,int cc, int n, int m,int &ds, int ans){
        if(cr==n && cc==m){
            ds=min(ds,max(ans,grid[cr][cc]));
            return ;
        }
        // out of bound
        if(cr<0 || cr>n || cc<0 || cc>m){
            return ;
        }
        mark[cr][cc]=true;

        ans=max(ans,grid[cr][cc]);
        // north
        if(cr>0 && mark[cr-1][cc]==false){
            solve(grid, mark, cr-1, cc, n, m, ds, ans);
        }
        // south
        if(cr<n && mark[cr+1][cc]==false){
            solve(grid, mark, cr+1, cc, n, m, ds, ans);
        }
        // east
        if(cc<m && mark[cr][cc+1]==false){
            solve(grid, mark, cr, cc+1, n, m, ds, ans);
        }
        // west
        if(cc>0 && mark[cr][cc-1]==false){
            solve(grid, mark, cr, cc-1, n, m, ds, ans);
        }

        mark[cr][cc]=false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        
        int ds=INT_MAX;
        solve(grid, mark, 0,0,n-1,m-1,ds,INT_MIN);

        return ds;
    }
};