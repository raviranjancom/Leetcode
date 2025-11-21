class Solution {
public:
    bool check(vector<vector<int>>& graph,vector<int> &visited,int start){
        queue<int> q;
        q.push(start);
        visited[start]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:graph[u]){
                if(visited[v]!=-1){
                    if(visited[u]==visited[v]) return false;
                }
                else{
                    visited[v]=(visited[u]==0)?1:0;
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(check(graph,visited,i)==false) return false;
            }
        }
        return true;
    }
};
