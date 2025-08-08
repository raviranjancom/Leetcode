class Solution {
public:
    void DFS(int n, vector<vector<int>>& edges,vector<int> &visited, int source, int destination,bool &ans){
        if(source==destination){
            ans = true;
            return ;
        }
        if(visited[source]==0){
            visited[source]=1;
            for(int i=0;i<edges.size();i++){
                if(edges[i][0]==source || edges[i][1]==source){
                    int k=(edges[i][0]==source)?1:0;
                    DFS(n,edges,visited,edges[i][k],destination,ans);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n,0);
        bool ans=false;
        DFS(n,edges,visited,source,destination,ans);
        return ans;
    }
};
