class Solution {
public:
    bool pacific(vector<vector<int>>& heights,vector<vector<bool>>& marked, int cr, int cc,vector<vector<int>> &dp){
        if(cr==-1 || cc==-1){
            return true;
        }
        if(dp[cr][cc]!=-1){
            return dp[cr][cc];
        }
        marked[cr][cc]=true;

        bool north=(cr-1==-1 || (heights[cr-1][cc]<=heights[cr][cc] && marked[cr-1][cc]==false))?pacific(heights,marked,cr-1,cc,dp):false;
        bool south=(cr+1<heights.size() &&  heights[cr+1][cc]<=heights[cr][cc] && marked[cr+1][cc]==false)?pacific(heights,marked,cr+1,cc,dp):false;
        bool east=(cc+1<heights[0].size() && heights[cr][cc+1]<=heights[cr][cc] && marked[cr][cc+1]==false)?pacific(heights,marked,cr,cc+1,dp):false;
        bool west=(cc-1==-1 || (heights[cr][cc-1]<=heights[cr][cc] && marked[cr][cc-1]==false))?pacific(heights,marked,cr,cc-1,dp):false;

        marked[cr][cc]=false;
        return dp[cr][cc]=(north || south || east || west);
    }
    bool atlantic(vector<vector<int>>& heights,vector<vector<bool>>& marked, int cr, int cc,vector<vector<int>> &dp){
        if(cr==heights.size() || cc==heights[0].size()){
            return true;
        }
        if(dp[cr][cc]!=-1){
            return dp[cr][cc];
        }
        marked[cr][cc]=true;

        bool north=(cr-1>-1 && heights[cr-1][cc]<=heights[cr][cc] && marked[cr-1][cc]==false)?atlantic(heights,marked,cr-1,cc,dp):false;
        bool south=((cr+1==heights.size()) || (cr+1<heights.size() &&  heights[cr+1][cc]<=heights[cr][cc] && marked[cr+1][cc]==false))?atlantic(heights,marked,cr+1,cc,dp):false;
        bool east=((cc+1==heights[0].size()) || (cc+1<heights[0].size() && heights[cr][cc+1]<=heights[cr][cc] && marked[cr][cc+1]==false))?atlantic(heights,marked,cr,cc+1,dp):false;
        bool west=(cc-1>-1 && heights[cr][cc-1]<=heights[cr][cc] && marked[cr][cc-1]==false)?atlantic(heights,marked,cr,cc-1,dp):false;

        marked[cr][cc]=false;
        return dp[cr][cc]=(north || south || east || west);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>> marked(n,vector<bool>(m,false));
        vector<vector<int>> pacific_dp(n,vector<int>(m,-1));
        vector<vector<int>> atlantic_dp(n,vector<int>(m,-1));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific(heights,marked,i,j,pacific_dp) && atlantic(heights,marked,i,j,atlantic_dp)){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
