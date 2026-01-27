class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges){
        vector<vector<pair<pair<int,int>,bool>>> Adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            Adj[u].push_back({{v,wt},false});
            Adj[v].push_back({{u,wt},true});
        }
        queue<pair<int,int>> q; // dist,node
        vector<int> dist(n,1e9);
        dist[0]=0;
        q.push({0,0});
        while(!q.empty()){
            auto t=q.front();   q.pop();
            int node=t.second;
            int prevWt=t.first;
            for(auto &it:Adj[node]){
                int u=it.first.first;
                int wt=it.first.second;
                bool flag=it.second;
                int cost=prevWt+wt+((flag)?wt:0);
                if(dist[u]>cost){
                    dist[u]=cost;
                    q.push({cost,u});
                }
            }
        }
        return (dist[n-1]==1e9)?-1:dist[n-1];
    }
};
