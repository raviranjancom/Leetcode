class Solution {
public:
    typedef pair<int,pair<int,int>> pp;   // height ---> (x,y)
    vector<vector<int>> directions={{0,-1}, {0,1}, {-1,0}, {1,0}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size(),m=heightMap[0].size();
        priority_queue<pp, vector<pp>, greater<>> pq;
        vector<vector<bool>> marked(n, vector<bool>(m,false));

        // collecting boundaries
        for(int i=0;i<n;i++){
            pq.push({heightMap[i][0],{i,0}});
            marked[i][0]=true;
        }
        for(int i=0;i<m;i++){
            pq.push({heightMap[0][i],{0,i}});
            marked[0][i]=true;
        }
        for(int i=0;i<m;i++){
            pq.push({heightMap[n-1][i],{n-1,i}});
            marked[n-1][i]=true;
        }
        for(int i=0;i<n;i++){
            pq.push({heightMap[i][m-1],{i,m-1}});
            marked[i][m-1]=true;
        }


        int water=0;
        while(!pq.empty()){
            auto top_ele = pq.top();   pq.pop();
            int height=top_ele.first;
            int x=top_ele.second.first;
            int y=top_ele.second.second;
            for(vector<int>& dir : directions){
                int x_=x+dir[0];
                int y_=y+dir[1];

                if(x_>=0 && y_>=0 && x_<n && y_<m && marked[x_][y_]==false){
                    water += max(height - heightMap[x_][y_],0);
                    pq.push({max(height, heightMap[x_][y_]),{x_,y_}});
                    marked[x_][y_]=true;
                }
            }
        }
        return water;
    }
};
