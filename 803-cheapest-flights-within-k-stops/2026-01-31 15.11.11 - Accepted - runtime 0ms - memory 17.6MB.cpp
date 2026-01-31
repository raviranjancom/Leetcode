class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> Adj(n);   // node,cost
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int p=flights[i][2];

            Adj[u].push_back({v,p});
        }
        queue<pair<int,pair<int,int>>> q;   // stops,node,dist
        vector<int> dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto t=q.front(); q.pop();
            int stop=t.first;
            int node=t.second.first;
            int prevDist=t.second.second;

            for(auto &it:Adj[node]){
                int newNode=it.first;
                int newCost=it.second;

                if(stop<=k && dist[newNode]>prevDist+newCost){
                    dist[newNode]=prevDist+newCost;
                    q.push({stop+1,{newNode,prevDist+newCost}});
                }
            }
        }
        return (dist[dst]==1e9)?-1:dist[dst];
    }
};
// Note : dont use distance vector with distance as first value for comparison beacuse there may be stored some minimum distance already which is not valid for reaching at the end within k stops so u need to store the larger distannces which may be valid instead use the k as first comparison parameter in pq. but since k increase sequencely we dont need pq q will be fine here.
