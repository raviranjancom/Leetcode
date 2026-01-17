class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius){
        int n=towers.size();
        int cx=center[0],cy=center[1];
        map<int,pair<int,int>> mp;
        int maxq=-1;
        for(int i=0;i<n;i++){
            int x=towers[i][0];
            int y=towers[i][1];
            int q=towers[i][2];
            
            int dist=abs(cx-x)+abs(cy-y);

            if(dist<=radius){
                maxq=max(maxq,q);
                if(mp.find(q)!=mp.end()){
                    if(mp[q].first>x){
                        mp[q]={x,y};
                    }
                    else if(mp[q].first==x && mp[q].second>y){
                        mp[q]={x,y};
                    }
                }
                else{
                    mp[q]={x,y};
                }
            }
        }
        if(mp.size()==0) return {-1,-1};
        return {mp[maxq].first,mp[maxq].second};
    }
};