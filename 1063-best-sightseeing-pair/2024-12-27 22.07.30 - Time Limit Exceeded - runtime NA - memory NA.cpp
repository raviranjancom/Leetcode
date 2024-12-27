class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int ans=INT_MIN,m=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                m=values[i]+i+values[j]-j;
                ans<m?ans=m:ans=ans;
            }
        }
        return ans;
    }
};