class Solution {
public:
    bool static comparator(vector<int> &a, vector<int> &b){
        if(a[0]<b[0]){
            return true;
        }
        else if(a[0] == b[0] && a[1] > b[1]){
            return true;
        }
        return false;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        sort(points.begin(),points.end(),comparator);
        for(int i=0;i<n;i++){
            int max_y=INT_MIN;
            for(int j=i+1;j<n;j++){
                if(points[i][1] >= points[j][1]){
                    if(max_y < points[j][1]){
                        ans++;
                        max_y=points[j][1];
                    }
                }
            }
        }
        return ans;
    }
};
