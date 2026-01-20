class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights){
        int n=heights.size(),m=heights.size();
        vector<vector<int>> visited(n,vector<int>(m,INT_MAX));
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>> pq;
        pq.push({{0,0},0});
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
            for(auto &dir:directions){
                int x=t.first.first+dir[0];
                int y=t.first.second+dir[1];
                if(x>=0 && x<n && y>=0 && y<m && visited[x][y]>max(t.second,abs(heights[t.first.first][t.first.second]-heights[x][y]))){
                    int r=max(t.second,abs(heights[t.first.first][t.first.second]-heights[x][y]));
                    pq.push({{x,y},r});
                    visited[x][y]=r;
                }
            }
        }
        return visited[n-1][m-1];
    }
};
