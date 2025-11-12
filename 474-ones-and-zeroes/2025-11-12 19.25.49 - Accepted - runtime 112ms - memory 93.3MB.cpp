class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<string> &strs,vector<vector<int>> &mp,int m, int n, int idx){
        if(m<0 || n<0 || idx>=strs.size()){
            return 0;
        }
        if(dp[m][n][idx]!=-1) return dp[m][n][idx];
        //take
        int x=INT_MIN;
        if(m-mp[idx][0]>=0 && n-mp[idx][1]>=0) x=1+solve(strs,mp,m-mp[idx][0],n-mp[idx][1],idx+1);
        // not take
        int y=solve(strs,mp,m,n,idx+1);

        return dp[m][n][idx]=max(x,y);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.assign(m+1,vector<vector<int>>(n+1,vector<int>(strs.size(),-1)));    // m,n,idx
        vector<vector<int>> mp(strs.size(),vector<int>(2,0));
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0'){
                    mp[i][0]++;
                }
                else{
                    mp[i][1]++;
                }
            }
        }
        return solve(strs,mp,m,n,0);
    }
};