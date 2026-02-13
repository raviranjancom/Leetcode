class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads){
        vector<vector<pair<long long,long long>>> Adj(n);
        for(int i=0;i<roads.size();i++){
            long long u=roads[i][0];
            long long v=roads[i][1];
            long long wt=roads[i][2];

            Adj[u].push_back({v,wt});
            Adj[v].push_back({u,wt});
        }
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq; // dist, node
        vector<long long> ans(n,0);
        ans[0]=1;
        vector<long long> dist(n,LLONG_MAX);
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            for(auto &it:Adj[t.second]){
                if(1LL*dist[it.first]>1LL*(t.first+it.second)){
                    dist[it.first]=1LL*(t.first+it.second);
                    pq.push({1LL*(t.first+it.second),it.first});
                    ans[it.first]=(ans[t.second])%mod;
                }
                else if(dist[it.first]==1LL*(t.first+it.second)){
                    dist[it.first]=1LL*(t.first+it.second);
                    ans[it.first]=(ans[it.first]+ans[t.second])%mod;
                }
            }
        }
        return ans[n-1];
    }
};