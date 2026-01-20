class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& heights,vector<vector<bool>> &marked,int cr,int cc,int n,int m){
        if(cr==n-1 && cc==m-1){
            return 0;
        }
        if(cr==n || cc==m){
            return 0;
        }
        if(dp[cr][cc]!=1e7) return dp[cr][cc];
        if(!marked[cr][cc]){
            int ans=1e7;
            vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
            for(auto &dir:directions){
                int x=cr+dir[0];
                int y=cc+dir[1];
                marked[cr][cc]=true;
                if(x<n && x>=0 && y<m && y>=0 && marked[x][y]==false){
                    ans=min(ans,max(abs(heights[cr][cc]-heights[x][y]),solve(heights,marked,x,y,n,m)));
                }
                marked[cr][cc]=false;
            }
            return ans;
        }
        return 1e7;
    }
    int minimumEffortPath(vector<vector<int>>& heights){
        int n=heights.size(),m=heights[0].size();
        dp.resize(n,vector<int>(m,1e7));
        // Dp not possible because the answer depends on the current marked values meaning the current stack values.
        vector<vector<bool>> marked(n,vector<bool>(m,false));
        return solve(heights,marked,0,0,n,m);
    }
};
