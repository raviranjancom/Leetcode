class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings){
        map<int,set<int>> mp;
        for(auto &it:buildings){
            int u=it[0];
            int v=it[1];
            mp[n+1-v].insert(u);
        }
        int startY=mp.begin()->first;
        int endY=mp.rbegin()->first;
        int ans=0;
        for(auto it:buildings){
            int u=it[0];
            int v=it[1];
            if(n+1-v==startY || n+1-v==endY){
                continue;
            }
            else if((*mp[n+1-v].begin())==u || (*mp[n+1-v].rbegin())==u){
                continue;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};
