class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points){
        int n=points.size();
        int ans=0;
        for(auto i=1;i<n;i++){
            int x1=points[i-1][0],y1=points[i-1][1];
            int x2=points[i][0],y2=points[i][1];

            int x=abs(x2-x1);
            int y=abs(y2-y1);
            ans+=min(x,y)+abs(x-y);
        }
        return ans;
    }
};
