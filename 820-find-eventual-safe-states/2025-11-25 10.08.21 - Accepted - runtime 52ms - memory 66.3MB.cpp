class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n=graph.size();
        vector<vector<int>> Adj(n);
        for(int i=0;i<n;i++){
            for(auto j:graph[i]){
                Adj[j].push_back(i);
            }
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto j:Adj[i]){
                indegree[j]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x=q.front(); q.pop();
            for(auto it:Adj[x]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
