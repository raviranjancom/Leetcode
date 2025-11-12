class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int n,int m,vector<vector<bool>> &mark,int &p_color){
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        image[sr][sc]=color;
        mark[sr][sc]=true;
        for(auto &it:directions){
            int x=sr+it[0];
            int y=sc+it[1];
            if(x>=0 && x<n && y>=0 && y<m && !mark[x][y] && image[x][y]==p_color){
                dfs(image,x,y,color,n,m,mark,p_color);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        int p_color=image[sr][sc];
        dfs(image,sr,sc,color,n,m,mark,p_color);
        return image;
    }
};
