class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<bool>& visited,vector<bool>& path,vector<int>& ans,int start){
        if(visited[start]==true && path[start]==true){
            return false;
        }
        if(visited[start]==true){
            return true;
        }
        visited[start]=true;
        path[start]=true;
        for(auto it:graph[start]){
            if(dfs(graph,visited,path,ans,it)==false) return false;
        }
        ans.push_back(start);
        path[start]=false;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n=graph.size();
        vector<bool> visited(n,false);
        vector<bool> path(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            dfs(graph,visited,path,ans,i);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
