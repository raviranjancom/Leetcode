class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> visited(n,-1);
        queue<int> q;
        q.push(0);
        visited[0]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:graph[u]){
                if(visited[v]!=-1){
                    if(visited[u]==visited[v]) return false;
                }
                else{
                    visited[v]=(u==0)?1:0;
                    q.push(v);
                }
            }
        }
        return true;
    }
};
