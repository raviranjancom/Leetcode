class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads){
        vector<vector<pair<int,int>>> Adj(n);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int wt=roads[i][2];

            Adj[u].push_back({v,wt});
            Adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // dist, node
        vector<int> ans(n,0);
        ans[0]=1;
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            for(auto &it:Adj[t.second]){
                if(dist[it.first]>t.first+it.second){
                    dist[it.first]=t.first+it.second;
                    pq.push({t.first+it.second,it.first});
                    ans[it.first]=(ans[t.second])%mod;
                }
                else if(dist[it.first]==t.first+it.second){
                    dist[it.first]=t.first+it.second;
                    ans[it.first]=(ans[it.first]+ans[t.second])%mod;
                }
            }
        }
        return ans[n-1];
    }
};