class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        vector<vector<pair<int,int>>> Adj(n);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];

            Adj[u-1].push_back({v-1,wt});
        }
        vector<int> dist(n,1e9);
        k-=1;
        dist[k]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;    // time, node
        pq.push({0,k});
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            int node=t.second;
            int time=t.first;

            for(auto it:Adj[node]){
                if(it.second+time<dist[it.first]){
                    dist[it.first]=it.second+time;
                    pq.push({it.second+time,it.first});
                }
            }
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            cout<<dist[i]<<" ";
            maxi=max(maxi,dist[i]);
        }
        if(maxi==1e9) return -1;
        return maxi;
    }
};