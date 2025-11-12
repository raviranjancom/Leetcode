class Solution {
public:
    bool dfs(int n,vector<vector<int>>& Adj, int source, int destination,vector<bool> &visited){
        if(source==destination) return true;
        visited[source]=true;
        for(auto &it:Adj[source]){
            if(!visited[it]){
                return dfs(n,Adj,it,destination,visited);
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination){
        vector<vector<int>> Adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        return dfs(n,Adj,source,destination,visited);
    }
};
