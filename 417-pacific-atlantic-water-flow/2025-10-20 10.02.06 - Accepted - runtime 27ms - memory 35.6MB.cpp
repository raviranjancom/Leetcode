class Solution {
public:
    void solve_p(vector<vector<int>>& heights, map<vector<int>,int> &ans, vector<vector<bool>> &mark1, int x, int y, int px, int py){
        if(x<0 || y<0 || x>=heights.size() || y>=heights[0].size() || mark1[x][y]==true){
            return ;
        }
        if(px==-1 || py==-1) ans[{x,y}]++; 
        else if(heights[x][y] >= heights[px][py]) ans[{x,y}]++;
        else return ;
        mark1[x][y]=true;
        solve_p(heights, ans, mark1, x+1, y,x,y);
        solve_p(heights, ans, mark1, x, y+1,x,y);
        solve_p(heights, ans, mark1, x-1, y,x,y);
        solve_p(heights, ans, mark1, x, y-1,x,y);
    }

    void solve_a(vector<vector<int>>& heights, map<vector<int>,int> &ans, vector<vector<bool>> &mark2, int x, int y, int px, int py){
        if(x<0 || y<0 || x>=heights.size() || y>=heights[0].size() || mark2[x][y]==true){
            return ;
        }
        if(px==-1 || py==-1) ans[{x,y}]++; 
        else if(heights[x][y] >= heights[px][py]) ans[{x,y}]++;
        else return ;
        mark2[x][y]=true;
        solve_a(heights, ans, mark2, x+1, y,x,y);
        solve_a(heights, ans, mark2, x, y+1,x,y);
        solve_a(heights, ans, mark2, x-1, y,x,y);
        solve_a(heights, ans, mark2, x, y-1,x,y);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        map<vector<int>,int> ans;
        vector<vector<bool>> mark1(n,vector<bool>(m,false)),mark2(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            solve_p(heights, ans, mark1, i, 0, -1, -1);
        }
        for(int i=0;i<m;i++){
            solve_p(heights, ans, mark1, 0, i, -1, -1);
        }

        for(int i=0;i<n;i++){
            solve_a(heights, ans, mark2, i, m-1, -1, -1);
        }
        for(int i=0;i<m;i++){
            solve_a(heights, ans, mark2, n-1, i, -1, -1);
        }
        vector<vector<int>> res;
        for(auto it:ans){
            if(it.second>1) res.push_back(it.first);
        }
        return res;
    }
};
