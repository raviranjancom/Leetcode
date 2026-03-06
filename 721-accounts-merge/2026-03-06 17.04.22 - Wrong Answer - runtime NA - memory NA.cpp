class DSU{
    public:
        vector<int> parent;
        vector<int> size;
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int upU=findUPar(u);
        int upV=findUPar(v);
        if(upU==upV) return ;
        if(size[upU]<size[upV]){
            parent[upU]=upV;
            size[upV]+=size[upU];
        }
        else{
            parent[upV]=upU;
            size[upU]+=size[upV];
        }
    }
};
class Solution {
public:
    bool hasCommon(vector<string> &u, vector<string> &v){
        for(int i=1;i<u.size();i++){
            for(int j=1;j<v.size();j++){
                if(u[i]==v[j]){
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        int n=accounts.size();
        DSU ds(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(hasCommon(accounts[i],accounts[j])){
                    ds.unionBySize(i,j);
                }
            }
        }
        vector<vector<string>> ans;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[ds.findUPar(i)].push_back(i);
        }
        for(auto &it:mp){
            set<string> x;
            x.insert(accounts[it.second[0]][0]);
            for(auto id:it.second){
                for(int j=1;j<accounts[id].size();j++){
                    x.insert(accounts[id][j]);
                }
            }
            vector<string> str;
            for(auto &it:x){
                str.push_back(it);
            }
            ans.push_back(str);
        }
        return ans;
    }
};
