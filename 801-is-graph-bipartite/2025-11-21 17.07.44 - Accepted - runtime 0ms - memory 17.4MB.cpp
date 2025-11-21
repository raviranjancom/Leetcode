class Solution {
public:
    bool check(vector<vector<int>>& graph,vector<int> &visited,int start,int color){
        if(visited[start]!=-1){
            if(visited[start]!=color){
                return false;
            }
            else{
                return true;
            }
        }
        visited[start]=color;
        int newcolor=(color==0)?1:0;
        for(auto v:graph[start]){
            if(check(graph,visited,v,newcolor)==false) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
        int n=graph.size();
        vector<int> visited(n,-1);
        for(int i=0;i<n;i++){
            if(visited[i]==-1){
                if(check(graph,visited,i,0)==false) return false;
            }
        }
        return true;
    }
};