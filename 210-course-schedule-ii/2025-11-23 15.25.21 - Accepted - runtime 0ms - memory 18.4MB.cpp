class Solution {
public:
    bool dfs(vector<vector<int>>& Adj,vector<bool> &visited,vector<bool> &path,int start,vector<int> &ans){
        if(visited[start]==true && path[start]==true){
            return true;
        }
        else if(visited[start]==true){
            return false;
        }
        visited[start]=true;
        path[start]=true;
        for(auto it:Adj[start]){
            if(dfs(Adj,visited,path,it,ans)) return true;
        }
        ans.push_back(start);
        path[start]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            Adj[u].push_back(v);
        }
        vector<bool> visited(numCourses,false);
        vector<bool> path(numCourses,false);
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(dfs(Adj,visited,path,i,ans)) return {};
        }
        return ans;
    }
};
