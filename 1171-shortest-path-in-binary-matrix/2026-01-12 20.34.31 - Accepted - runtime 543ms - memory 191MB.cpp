class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        if(grid[0][0]==1) return -1;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; // {dist, node}
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            int prevDist=t.first;
            auto node=t.second;

            vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
            for(auto &dir:direction){
                int x=node.first+dir[0];
                int y=node.second+dir[1];

                if(x>=0 && x<n && y>=0 && y<m){
                    if(grid[x][y]==0 && dist[x][y]>prevDist+1){
                        dist[x][y]=prevDist+1;
                        pq.push({prevDist+1,{x,y}});
                    }
                }
            }
        }
        int ans=dist[n-1][m-1];
        return ans=(ans==1e9)?-1:ans+1;
    }
};
