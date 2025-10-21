class Solution {
public:
    bool solve(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j,int t){
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || visited[i][j]==true || grid[i][j]>t){
            return false;
        }
        
        if(i==grid.size()-1 && j==grid.size()-1){
            return true;
        }
        visited[i][j]=true;
        if(solve(grid,visited,i-1,j,t) || solve(grid,visited,i+1,j,t) || solve(grid,visited,i,j-1,t) || solve(grid,visited,i,j+1,t)){
            return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),ans=n*n-1;
        int l=grid[0][0],r=n*n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<vector<bool>> visited(n,vector<bool>(n,false));
            if(solve(grid,visited,0,0,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};