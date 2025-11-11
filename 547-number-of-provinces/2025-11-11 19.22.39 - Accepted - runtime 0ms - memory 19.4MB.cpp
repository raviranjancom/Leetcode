class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool> &visited,int start){
        visited[start]=true;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[start][i]==1 && visited[i]==false){
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int ans=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(isConnected,visited,i);
            }
        }
        return ans;
    }
};