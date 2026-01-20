class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights){
        int n=heights.size(),m=heights[0].size();
        if(n==1 && m==1) return 0;
        vector<vector<int>> visited(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
            for(auto &dir:directions){
                int x=t.second.first+dir[0];
                int y=t.second.second+dir[1];
                if(x>=0 && x<n && y>=0 && y<m && visited[x][y]>max(t.first,abs(heights[t.second.first][t.second.second]-heights[x][y]))){
                    int r=max(t.first,abs(heights[t.second.first][t.second.second]-heights[x][y]));
                    pq.push({r,{x,y}});
                    visited[x][y]=r;
                }
            }
        }
        return visited[n-1][m-1];
    }
};
