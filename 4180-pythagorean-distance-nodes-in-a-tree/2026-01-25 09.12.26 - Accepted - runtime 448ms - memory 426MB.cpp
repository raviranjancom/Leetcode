class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z){
        vector<vector<int>> Adj(n);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];

            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        auto bfs=[&](int start){
            vector<int> dist(n,-1);
            queue<int> q;
            q.push(start);
            dist[start]=0;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:Adj[u]){
                    if(dist[v]==-1){
                        dist[v]=dist[u]+1;
                        q.push(v);
                    }
                }
            }
            return dist;
        };
        vector<int> dx=bfs(x),dy=bfs(y),dz=bfs(z);
        int ans=0;
        for(int i=0;i<n;i++){
            if(dx[i]==-1) continue;
            long long d1=dx[i];
            long long d2=dy[i];
            long long d3=dz[i];

            vector<long long> d={d1,d2,d3};
            sort(d.begin(),d.end());
            if(d[0]*d[0]+d[1]*d[1]==d[2]*d[2]) ans++;
        }
               return ans;
    }
};
