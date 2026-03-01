class DSU{
    public:
        vector<int> parent;
        vector<int> size;
        DSU(int n){
            size.resize(n,1);
            for(int i=0;i<n;i++){
                parent.push_back(i);
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
    int val(int i,int j,int m){
        return i*m+j;
    }
    int largestIsland(vector<vector<int>>& grid){
        int ans=0;
        bool flag=false;
        int n=grid.size(),m=grid[0].size();
        DSU ds(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
                    for(auto &dir:directions){
                        int x=i+dir[0];
                        int y=j+dir[1];
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                            ds.unionBySize(val(x,y,m),val(i,j,m));
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    flag=true;
                    vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
                    unordered_set<int> st;
                    for(auto &dir:directions){
                        int x=i+dir[0];
                        int y=j+dir[1];
                        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                            st.insert(ds.findUPar(val(x,y,m)));
                        }
                    }
                    int sum=1;
                    for(auto it:st){
                        sum+=ds.size[it];
                    }
                    ans=max(ans,sum);
                    for(int i=0;i<n*m;i++){
                        ans=max(ans,ds.size[ds.findUPar(i)]);
                    }
                }
            }
        }
        if(!flag) return n*m;
        return ans;
    }
};
