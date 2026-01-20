class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> Adj(n);   // node,price
        int ans=INT_MAX;
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int p=flights[i][2];

            Adj[u].push_back({v,p});
        }
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq; // price, node, k
        pq.push({{0,src},k});
        while(!pq.empty()){
            auto t=pq.top(); pq.pop();
            int prevPrice=t.first.first;
            int node=t.first.second;
            int k_=t.second;

            if(node==dst){
                ans=min(ans,prevPrice);
                return ans;
            }
            else if(k_<0){
                continue;
            }
            else{
                for(auto &it:Adj[node]){
                    pq.push({{prevPrice+it.second, it.first}, k_-1});
                }
            }
        }
        return (ans==INT_MAX)?-1:ans;
    }
};
