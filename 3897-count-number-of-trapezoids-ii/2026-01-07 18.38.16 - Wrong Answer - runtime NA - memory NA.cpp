class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points){
        int n=points.size();
        map<float,map<float,int>> mp; // slope->intercept->count
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];

                float slope=(x2-x1==0)?1e18:(float)(y2-y1)/(float)(x2-x1);
                float intercept=y2-slope*x2;

                mp[slope][intercept]++;
            }
        }
        // calculating answer
        int ans=0;
        for(auto it:mp){
            int prevLines=0;
            for(auto jt:mp[it.first]){
                ans+=jt.second*prevLines;
                prevLines+=jt.second;
            }
        }
        return ans;
    }
};
