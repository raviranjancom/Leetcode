class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0,cntFresh=0,cnt=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j]==1){
                    cntFresh++;
                }
            }
        }

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            ans=max(ans,t);
            vector<vector<int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
            for(auto &dir:directions){
                int x=r+dir[0];
                int y=c+dir[1];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                    grid[x][y]=2;
                    q.push({{x,y},t+1});
                    cnt++;
                }
            }
        }
        if(cntFresh!=cnt) return -1;
        return ans;
    }
};
