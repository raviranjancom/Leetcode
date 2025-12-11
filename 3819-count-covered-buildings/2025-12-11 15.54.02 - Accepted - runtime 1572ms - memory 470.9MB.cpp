class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings){
        map<int,set<int>> mpY,mpX;
        for(auto &it:buildings){
            int u=it[0];
            int v=it[1];
            mpY[v].insert(u);
            mpX[u].insert(v);
        }

        int ans=0;
        for(auto it:buildings){
            int u=it[0];
            int v=it[1];
            if(*mpX[u].begin()==v || *mpX[u].rbegin()==v || *mpY[v].begin()==u || *mpY[v].rbegin()==u){
                continue;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};
