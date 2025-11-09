class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>> &adj,int id,vector<int> &idTrack,unordered_map<int,set<int>> &mp,vector<bool> visited){
        visited[node]=true;
        mp[id].insert(node);
        idTrack[node]=id;

        for(int it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,id,idTrack,mp,visited);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;
        for(auto &edge:connections){
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(c+1,false);
        vector<int> idTrack(c+1,-1);    // to track id of each node
        unordered_map<int,set<int>> mp;
        int nodeId=1;
        for(int node=1;node<=c;node++){
            if(!visited[node]){
                dfs(node,adj,nodeId,idTrack,mp,visited);
                nodeId++;
            }
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int x=queries[i][1];
            int id=idTrack[x];
            if(queries[i][0]==2){
                mp[id].erase(x);
            }
            else{
                if(mp[id].find(x)!=mp[id].end()){
                    ans.push_back(x);
                }
                else{
                    if(mp[id].empty()) ans.push_back(-1);
                    else ans.push_back(*mp[id].begin());
                }
            }
        }
        return ans;
    }
};





// unsuccessful attempt

// class Solution {
// public:
//     void create_grid(int c,vector<set<int>> &components, vector<int> &marked,vector<vector<int>>& connections){
//         int id=0;
//         unordered_map<int,int> grid;
//         // connected components
//         for(int i=0;i<connections.size();i++){
//             if(marked[connections[i][0]]!=-1 && marked[connections[i][1]]!=-1){
//                 continue;
//             }
//             else if(marked[connections[i][0]]!=-1 && marked[connections[i][1]]==-1){
//                 grid[connections[i][1]]=grid[connections[i][0]];
//                 marked[connections[i][1]]=grid[connections[i][0]];
//             }
//             else if(marked[connections[i][0]]==-1 && marked[connections[i][1]]!=-1){
//                 grid[connections[i][0]]=grid[connections[i][1]];
//                 marked[connections[i][0]]=grid[connections[i][1]];
//             }
//             else{
//                 grid[connections[i][0]]=id;
//                 grid[connections[i][1]]=id;
//                 marked[connections[i][0]]=id;
//                 marked[connections[i][1]]=id;
//                 id++;
//             }
//         }
//         // non connected components
//         for(int i=1;i<=c;i++){
//             if(marked[i]==-1){
//                 grid[i]=id;
//                 id++;
//                 marked[i]=id;
//             }
//         }
//         components.resize(id);
//         for(int i=1;i<=c;i++){
//             components[grid[i]].insert(i);
//         }
//         return ;
//     }
//     vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
//         vector<set<int>> components;
//         vector<int> marked(c+1,-1);
//         create_grid(c,components,marked,connections);
//         vector<bool> is_online(c+1,true);
//         vector<int> ans;
//         for(int i=0;i<queries.size();i++){
//             if(queries[i][0]==1){
//                 if(is_online[queries[i][1]]==true) ans.push_back(queries[i][1]);
//                 else{
//                     int key=marked[queries[i][1]];
//                     if(!components[key].empty()){
//                         int smallest=*components[key].begin();
//                         ans.push_back(smallest);
//                     }
//                 }
//             }
//             else{
//                 is_online[queries[i][1]]=false;
//                 int key=marked[queries[i][1]];
//                 auto it=components[key].find(queries[i][1]);
//                 if(it!=components[key].end()){
//                     components[key].erase(queries[i][1]);
//                 }
//             }
//         }
//         return ans;
//     }
// };
