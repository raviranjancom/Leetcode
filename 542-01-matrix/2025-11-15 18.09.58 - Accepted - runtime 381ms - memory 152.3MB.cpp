class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        // Approch : Find the distance of nearest 1 from 0
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
                else{
                    visited[i][j]=false;
                }
            }
        }
        // finding the values
        while(!q.empty()){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int level=q.front().second;
            q.pop();
            ans[x][y]=level;
            
            vector<vector<int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
            for(auto &dir:directions){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(x_>=0 && y_>=0 && x_<n && y_<m && visited[x_][y_]==false){
                    q.push({{x_,y_},level+1});
                    visited[x_][y_]=true;
                }
            }
        }
        return ans;
    }
};
