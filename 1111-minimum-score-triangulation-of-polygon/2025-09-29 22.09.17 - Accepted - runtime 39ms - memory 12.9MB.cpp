class Solution {
public:
    int solve(vector<int>& values, int start, int end, map<pair<int,int>,int> &dp){
        if(end-start<2){
            return 0;
        }
        auto y=dp.find({start,end});
        if(y!=dp.end()){
            return dp[{start,end}];
        }
        int ans=INT_MAX;
        for(int i=start+1;i<end;i++){
            int x=solve(values,start,i,dp)+values[start]*values[i]*values[end]+solve(values,i,end,dp);
            ans=min(ans,x);
        }
        return dp[{start,end}]=ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        map<pair<int,int>, int> dp;
        return solve(values,0,n-1,dp);
    }
};
