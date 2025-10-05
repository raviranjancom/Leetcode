class Solution {
public:
    bool pacific(vector<vector<int>>& heights,vector<vector<bool>>& marked, int cr, int cc){
        if(cr==-1 || cc==-1){
            return true;
        }
        marked[cr][cc]=true;

        bool north=(cr-1==-1 || (heights[cr-1][cc]<=heights[cr][cc] && marked[cr-1][cc]==false))?pacific(heights,marked,cr-1,cc):false;
        bool south=(cr+1<heights.size() &&  heights[cr+1][cc]<=heights[cr][cc] && marked[cr+1][cc]==false)?pacific(heights,marked,cr+1,cc):false;
        bool east=(cc+1<heights[0].size() && heights[cr][cc+1]<=heights[cr][cc] && marked[cr][cc+1]==false)?pacific(heights,marked,cr,cc+1):false;
        bool west=(cc-1==-1 || (heights[cr][cc-1]<=heights[cr][cc] && marked[cr][cc-1]==false))?pacific(heights,marked,cr,cc-1):false;

        marked[cr][cc]=false;
        return (north || south || east || west);
    }
    bool atlantic(vector<vector<int>>& heights,vector<vector<bool>>& marked, int cr, int cc){
        if(cr==heights.size() || cc==heights[0].size()){
            return true;
        }
        marked[cr][cc]=true;

        bool north=(cr-1>-1 && heights[cr-1][cc]<=heights[cr][cc] && marked[cr-1][cc]==false)?atlantic(heights,marked,cr-1,cc):false;
        bool south=((cr+1==heights.size()) || (cr+1<heights.size() &&  heights[cr+1][cc]<=heights[cr][cc] && marked[cr+1][cc]==false))?atlantic(heights,marked,cr+1,cc):false;
        bool east=((cc+1==heights[0].size()) || (cc+1<heights[0].size() && heights[cr][cc+1]<=heights[cr][cc] && marked[cr][cc+1]==false))?atlantic(heights,marked,cr,cc+1):false;
        bool west=(cc-1>-1 && heights[cr][cc-1]<=heights[cr][cc] && marked[cr][cc-1]==false)?atlantic(heights,marked,cr,cc-1):false;

        marked[cr][cc]=false;
        return (north || south || east || west);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<bool>> marked1(n,vector<bool>(m,false));
        vector<vector<bool>> marked2(n,vector<bool>(m,false));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific(heights,marked1,i,j) && atlantic(heights,marked2,i,j)){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
