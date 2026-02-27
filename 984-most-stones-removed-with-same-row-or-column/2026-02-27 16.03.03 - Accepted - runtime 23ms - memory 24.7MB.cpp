class DSU{
public:
    vector<int> parents;
    vector<int> size;
    DSU(int n){
        size.resize(n,1);
        parents.resize(n);
        for(int i=0;i<n;i++){
            parents[i]=i;
        }
    }
    int findUPar(int node){
        if(node==parents[node]) return node;
        return parents[node]=findUPar(parents[node]);
    }
    void unionBySize(int u,int v){
        int parU=findUPar(u);
        int parV=findUPar(v);
        if(parU==parV) return ;
        if(size[parU]>size[parV]){
            parents[parV]=parU;
            size[parU]+=size[parV];
        }
        else{
            parents[parV]=parU;
            size[parV]+=size[parU];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones){
        int n=stones.size();
        int nrow=0,ncol=0;
        unordered_map<int,int> mp;
        for(auto it:stones){
            nrow=max(nrow,it[0]);
            ncol=max(ncol,it[1]);
        }
        DSU ds(nrow+ncol+2);
        for(auto it:stones){
            int noderow=it[0];
            int nodecol=it[1]+nrow+1;
            ds.unionBySize(noderow, nodecol);
            mp[noderow]=1;
            mp[nodecol]=1;
        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findUPar(it.first)==it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};
