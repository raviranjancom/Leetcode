class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings){
        map<int,set<int>> mpY;   // x->y
        map<int,set<int>> mpX;   // y->x

        for(auto &it:buildings){
            mpY[it[0]].insert(it[1]);
            mpX[it[1]].insert(it[0]);
        }
        int ans=0;
        for(auto &it:buildings){
            int x=it[0];
            int y=it[1];

            if((*mpY[x].begin())==y || (*mpY[x].rbegin())==y) continue;
            else if((*mpX[y].begin())==x || (*mpX[y].rbegin())==x) continue;
            else ans++;
        }
        return ans;
    }
};
