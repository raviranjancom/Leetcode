class Solution {
public:
    int bfs(unordered_map<char,vector<pair<char,int>>> &Adj,char start,char target){
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
        pq.push({0,start});
        unordered_map<char,int> dist;
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            int cost=t.first;
            char node=t.second;
            for(auto &it:Adj[node]){
                int newCost=it.second;
                char u=it.first;
                int prevDist=(dist.find(u)==dist.end())?1e9:dist[u];
                if(newCost+cost<prevDist){
                    dist[u]=newCost+cost;
                    pq.push({dist[u],u});
                }
            }
        }
        return (dist.find(target)==dist.end())?-1:dist[target];
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost){
        unordered_map<char,vector<pair<char,int>>> Adj;
        for(int i=0;i<original.size();i++){
            Adj[original[i]].push_back({changed[i],cost[i]});
        }
        int ans=0;
        for(int i=0;i<source.size();i++){
            if(source[i]!=target[i]){
                int x=bfs(Adj,source[i],target[i]);
                if(x==-1){
                    return -1;
                }
                ans+=x;
            }
        }
        return ans;
    }
};
