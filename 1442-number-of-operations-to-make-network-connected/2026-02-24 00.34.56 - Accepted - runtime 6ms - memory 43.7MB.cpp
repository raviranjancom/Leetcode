class DSU{
    public:
        vector<int> parent;
        vector<int> size;
        DSU(int n){
            parent.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findUPar(int node){
            if(node==parent[node]) return node;
            return parent[node]=findUPar(parent[node]);
        }
        void unionBySize(int u,int v){
            int parU=findUPar(u);
            int parV=findUPar(v);
            if(parU==parV) return ;
            if(size[parU]>size[parV]){
                parent[parV]=parU;
                size[parU]+=size[parV];
            }
            else{
                parent[parU]=parV;
                size[parV]+=size[parU];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections){
        int carry=0;
        DSU ds(n);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];

            if(ds.findUPar(u)==ds.findUPar(v)){
                carry++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(ds.findUPar(i));
        }
        if(carry>=st.size()-1) return st.size()-1;
        return -1;
    }
};
