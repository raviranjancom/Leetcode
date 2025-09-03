class Solution {
public:
    bool check(vector<vector<int>>& points,int x1,int x2,int y1,int y2,int start,int i){
        for(int j=0;j<points.size();j++){
            if(j==start || j==i) continue;
            else if(points[j][0]<=max(x1,x2) && points[j][0]>=min(x1,x2) && points[j][1]<=max(y1,y2) && points[j][1]>=min(y1,y2)){
                return false;
            }
        }
        return true;
    }
    int solve(vector<vector<int>>& points, int n, int start){
        int ans=0;
        int x1=points[start][0],y1=points[start][1];
        for(int i=0;i<n;i++){
            if(start==i) continue;
            int x2=points[i][0],y2=points[i][1];
            if(x1 <= x2 && y1 >= y2){
                if(check(points,x1,x2,y1,y2,start,i)) {
                    ans++;
                }
            }
        }
        return ans;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=solve(points,n,i);
        }
        return ans;
    }
};